#include "../inc/libs.h"

void    create_pipe(int fd[2])
{
    t_shell *data;

    data = ft_start_shell();
    if (pipe(fd) == -1)
    {
        perror("pipe");
        free_exit(data);
        exit(1);
    }
}

pid_t    create_fork(void)
{
    pid_t   pid;
    t_shell *data;

    pid = fork();
    data = ft_start_shell();
    if (pid == -1)
    {
        perror("fork");
        free_exit(data);
        exit(1);
    }
    return (pid);
}

void	write_line_to_pipe(t_shell *data, char *line, int fd[2])
{
	line = expand_envvar(data, line);
	write(fd[1], line, ft_strlen(line));
	write(fd[1], "\n", 1);
	free(line);
}

char	*loop_heredoc(t_shell *data, t_command *current, int fd[2])
{
	char	*line;

	while (1)
	{
		line = readline("> ");
		// verificar se passaram sinal no meio do heredoc
		if (!line)
		{
			write(STDERR_FILENO, "-minishell: Warning: here-document delimited by end-of-file\n" , 60);
			break ;
		}
		if (ft_strcmp(line, current->heredoc_delim) == 0)
			break ;
		write_line_to_pipe(data, line, fd);
	}
	return (line);
}

int	execute_heredoc(t_shell *data , t_command *current, int fd[2])
{
	pid_t	pid;
	char	*line;

	pid = create_fork();
	if (pid == 0)
	{
		// configurar sinais
		line = loop_heredoc(data, current, fd);
		if (line)
			free(line);
		free_exit(data);
		exit(0);
	}
	return (pid);
}

int	heredoc_cmds(t_shell *data)
{
	t_command	*current;
	pid_t		pid;
	int			fd[2];
	int			return_status;

	current = data->commands;
	return_status = 0;
	while (current)
	{
		if (current->has_heredoc)
		{
			create_pipe(fd);
			pid = execute_heredoc(data, current, fd);
			waitpid(pid, &return_status, 0);
			//verificar return_status se nao foi um sinal

		}
		current = current->next;
	}
    return (return_status);
}

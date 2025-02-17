#include "../inc/libs.h"

void    create_pipe(int fd[2])
{
    t_shell *data;

    data = ft_start_shell();
    if (pipe(fd) == -1)
    {
        perror("pipe");
        free_exit(data);
        exit(EXIT_FAILURE);
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
        exit(EXIT_FAILURE);
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

void	loop_heredoc(t_shell *data, t_command *current, int fd[2])
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
	free(line);
}

#include "../inc/libs.h"

int is_builtin(char *cmd)
{
	if (ft_strcmp(cmd, "env") == 0 || ft_strcmp(cmd, "export") == 0 ||
		ft_strcmp(cmd, "exit") == 0 || ft_strcmp(cmd, "cd") == 0 ||
		ft_strcmp(cmd, "unset") == 0 || ft_strcmp(cmd, "pwd") == 0 ||
		ft_strcmp(cmd, "echo") == 0)
		return (1); // É built-in
	return (0); // Não é built-in
}

void	handle_child_heredoc(t_shell *data, t_command *current, int fd[2])
{
	close(fd[0]);
	loop_heredoc(data, current, fd);
	close(fd[1]);
	exit(0);
}

void	handle_parent_heredoc(t_command *current, int fd[2], pid_t pid)
{
	int	status;

	close(fd[1]);
	current->heredoc_fd = fd[0];
	current->heredoc_pid = pid;
	waitpid(pid, &status, 0);
}

void	create_heredoc(t_command *current)
{
	int		fd[2];
	pid_t	pid;

	create_pipe(fd);
	pid = create_fork();
	if (pid == 0)
		handle_child_heredoc(ft_start_shell(), current, fd);
	else
		handle_parent_heredoc(current, fd, pid);
}

void	handle_rerections(t_command *cmd)
{
	if (cmd->infile)
		redirect_input(cmd->infile);
	if (cmd->outfile)
	{
		if (cmd->append)
			redirect_output_append(cmd->outfile);
		else
			redirect_output(cmd->outfile);
	}
	if (cmd->has_heredoc)
	{
		dup2(cmd->heredoc_fd, STDIN_FILENO);
		close(cmd->heredoc_fd);
	}
}

void	execute_builtin(t_shell *data, t_command *cmd)
{
	if (ft_strcmp(cmd->cmd, "env") == 0)
		mini_env(data->envvar);
	else if (ft_strcmp(cmd->cmd, "export") == 0)
		print_export(data);
	else if (ft_strcmp(cmd->cmd, "exit") == 0)
	{
		free_exit(data);
		exit(EXIT_FAILURE);
	}
	else if (ft_strcmp(cmd->cmd, "cd") == 0)
		cd(data, cmd->args);
	else if (ft_strcmp(cmd->cmd, "unset") == 0)
		unset(data, cmd->args);
	else if (ft_strcmp(cmd->cmd, "pwd") == 0)
		mini_pwd(data);
	else if (ft_strcmp(cmd->cmd, "echo") == 0)
		mini_echo(cmd->args, 1);
}

void    execute_commands(t_shell *data)
{
	t_command   *cmd;
	pid_t		pid;
	int			status;

	cmd = data->commands;
	while (cmd != NULL)
	{
		if (cmd->has_heredoc) // 1. Heredoc
			create_heredoc(cmd);
		pid = create_fork();
		if (pid == 0)
		{
			handle_rerections(cmd); // Verificar redirects
			if (is_builtin(cmd->cmd)) // 2. Builtins
				execute_builtin(data, cmd);
			else // 3. Comandos simples (externos)
				external_commands(data, cmd->args);
			exit(EXIT_SUCCESS);
		}
		else
		{
			waitpid(pid, &status, 0);
			data->return_status = WEXITSTATUS(status);
			if (WEXITSTATUS(status) < 0)
			{
				perror("Minishell");
				exit(EXIT_FAILURE);
			}
			if (WEXITSTATUS(status) > 0)
				exit(EXIT_FAILURE);
		}
		cmd = cmd->next;
	}
}

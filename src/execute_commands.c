#include "../inc/libs.h"

void	handle_child_heredoc(t_shell *data, t_command *current, int fd[2])
{
	close(fd[0]);
	ft_config_signals(0);
	loop_heredoc(data, current, fd);
	close(fd[1]);
	exit(0);
}

void	handle_parent_heredoc(t_command *current, int fd[2], pid_t pid)
{
	int	status;

	close(fd[1]); // fechar a escrita
	current->heredoc_fd = fd[0]; // salvar para caso precise dps
	current->heredoc_pid = pid;
	waitpid(pid, &status, 0);
}

void	create_heredoc(t_command *current)
{
	int		fd[2];
	pid_t	pid;

	create_pipe(fd); // cria o pipe e em caso de erro da exit
	pid = create_fork();// cria o fork e em caso de erro da exit
	if (pid == 0)
		handle_child_heredoc(ft_start_shell(), current, fd);
	else
	{
		close(fd[1]); // fechar a escrita
		current->heredoc_fd = fd[0]; // salvar para caso precise dps
		current->heredoc_pid = pid;
	}
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

void execute_commands(t_shell *data)
{
    t_command *cmd;
    pid_t pid;
    int status;

    cmd = data->commands;
    while (cmd != NULL)
	{
        if (cmd->has_heredoc)
            create_heredoc(cmd); // Cria o heredoc se o comando precisar
		if (ft_strcmp(cmd->cmd, "exit") == 0)
		{
			execute_builtin(data, cmd); // Executa exit diretamente no pai
			return; // Sai de execute_commands (encerra o Minishell)
		}
        pid = create_fork();
        if (pid == 0) // Processo filho
		{
            handle_rerections(cmd); // Lida com redirecionamentos (incluindo heredoc)
            if (is_builtin(cmd->cmd))
                execute_builtin(data, cmd);
            else
                external_commands(data, cmd->args);
            exit(data->return_status); // Sai com o status do comando
        }
		else // Processo pai
		{
            waitpid(pid, &status, 0);
            data->return_status = WEXITSTATUS(status);
			set_questionvar(data);
        }
        cmd = cmd->next;
    }
}

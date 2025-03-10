#include "../inc/libs.h"

void	exe(t_shell *data)
{
	t_command	*cmd;
	pid_t		pid;
	int			status;
	
	cmd = data->commands;
	// Primeiro, processa todos os heredocs antes de executar os comandos
	while (cmd)
	{
		if (cmd->has_heredoc)
			create_heredoc(cmd);
		cmd = cmd->next;
	}
	cmd = data->commands;
	if (cmd->has_pipe)
		handle_pipeline(data, cmd);
	else
	{
		if (is_builtin(cmd->cmd))
			execute_builtin(data, cmd);
		else
		{
			pid = create_fork();
			if (pid == 0)
				exec_external_cmd(cmd->args, envvar_array(data->envvar));
			else
			{
				waitpid(pid, &status, 0);
				data->return_status = WEXITSTATUS(status);
				set_questionvar(data);
			}
		}
	}
}

/* TODO: lidar com os redirects quando nao tiver pipes (else) */
/* TODO: "cat << e > a.txt | ls -l"   deve cancelar tudo */

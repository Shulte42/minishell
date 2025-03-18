#include "../inc/libs.h"

void	handle_pipeline(t_shell *data, t_command *cmd)
{
	int			fd[2]; // Pipe atual
	int			prev_fd; // Pipe anterior
	pid_t		pid;

	prev_fd = -1; // Nenhum pipe antes do primeiro comando
	while (cmd)
	{
		if (cmd->has_pipe)
			create_pipe(fd);
		pid = create_fork();
		if (pid == 0) // Processo filho
		{
			// Redirecionamentos (tem prioridade sobre pipes)
			if (handle_redirects(cmd))
				exit(1);
			// Se nao houve redirecionamento de entrada, usa o pipe anterior
			if (!cmd->infile && prev_fd != -1)
			{
				dup2(prev_fd, STDIN_FILENO);
				close(prev_fd);
			}
			// Se nao houve redirecionamento de saida, usa o pipe atual
			if (!cmd->outfile && cmd->has_pipe)
			{
				dup2(fd[1], STDOUT_FILENO);
				close(fd[1]);
				close(fd[0]);
			}
			if (is_builtin(cmd->cmd))
				execute_builtin(data, cmd);
			else
				exec_external_cmd(cmd->args, envvar_array(data->envvar));
			exit(EXIT_SUCCESS);
		}
		else // Processo pai
		{
			if (prev_fd != -1)
				close(prev_fd); // Fechar a leitura do pipe anterior
			if (cmd->has_pipe) 
			{
				close(fd[1]); // Fechar a escrita do pipe atual
				prev_fd = fd[0]; // O próximo comando vai ler deste pipe
			}
			waitpid(pid, NULL, 0); // Espera o processo filho
		}
		cmd = cmd->next;
	}
}


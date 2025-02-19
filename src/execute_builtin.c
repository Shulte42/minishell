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

void	execute_builtin(t_shell *data, t_command *cmd)
{
	if (ft_strcmp(cmd->cmd, "env") == 0)
		mini_env(data->envvar);
	else if (ft_strcmp(cmd->cmd, "export") == 0)
		print_export(data);
	else if (ft_strcmp(cmd->cmd, "exit") == 0)
	{
		free_exit(data);
		exit(data->return_status);
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

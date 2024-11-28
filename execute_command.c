#include "mini.h"

char	*get_command_path(char *cmd, char **envp)
{
	char	**all_paths;
	char	*current_path;
	char	*path;
	int		i;

	i = 0;
	while((ft_strnstr(envp[i], "PATH", 4)) == NULL)
		i++;
	all_paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (all_paths[i])
	{
		current_path = ft_strjoin(all_paths[i], "/");
		path = ft_strjoin_free(current_path, cmd);
		if (((access(path, F_OK)) == 0) && ((access(path, X_OK)) == 0))
		{
			free_array(all_paths);
			return (path);
		}
		free(path);
		i++;
	}
	free_array(all_paths);
	return (NULL);
}

void	execute_command(char **cmd, char **envp)
{
	char	*command_path;

	if (!cmd[0] || only_space(cmd[0]) || check_envp(envp))
		return ;
	command_path = get_command_path(cmd[0], envp);
	if (!command_path)
	{
		printf("%s: command not found\n", cmd[0]);
		exit(127);
	}
	execve(command_path, cmd, envp);
	free_array(cmd);
	free(command_path);
	perror("execve");
	exit(EXIT_FAILURE);
}

#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

int	only_space(char *str)
{
	int i;

	i = 0;
	while(str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

int	check_envp(char **envp)
{
	int	i;

	if (!envp || !*envp)
	{
		printf("environment not found\n");
		return (1);
	}
	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH", 5))
		{
			if (*(envp[i] + 5) != '\0')
				return (0);
			else
			{
				printf("PATH variable is empty\n");
				return (1);
			}
		}
		i++;
	}
	printf("PATH variable not found\n");
	return (1);
}

char	*ft_strjoin_free(const char *s1, const	char *s2)
{
	char	*str_join;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	str_join = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str_join)
		return (NULL);
	i = -1;
	while(s1[++i])
		str_join[i] = s1[i];
	j = -1;
	while(s2[++j])
		str_join[i++] = s2[j];
	str_join[i] = '\0';
	free((char *)s1);
	return (str_join);
}

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
	exit(1);
}

int	open_file(char *file, int flags, int mode)
{
	int	fd;

	fd = open(file, flags, mode);
	if (fd == -1)
	{
		perror(file);
		exit(1);
	}
	return (fd);
}

int main(int ac, char **av, char **envp)
{
	/*
		./mini 
	*/
	return (0);
}

#include "mini.h"

int main(int ac, char **av, char **envp)
{
	char	*input;
	char	**args;
	char	*pwd;
	t_mini	data;

	ft_bzero(&data, sizeof(data));
	data.envvar = copy_envvar(envp);
	data.pwd = getcwd(NULL, 0);
	while(1)
	{
		pwd = getcwd(NULL, 0);
		input = readline(ft_strjoin_free(pwd, "$ "));
		if (!input || !*input)
		{
			free(input);
			continue ;
		}
		add_history(input);
		args = ft_split(input, ' ');
		free(input);
		if (ft_strncmp(args[0], "exit", ft_strlen("exit")) == 0)
			break ;
		else if (ft_strncmp(args[0], "echo", ft_strlen("echo")) == 0)
			mini_echo(args, 1);
		else if(ft_strncmp(args[0], "pwd",ft_strlen("pwd")) == 0)
			mini_pwd();
		else if (ft_strncmp(args[0], "cd", ft_strlen("cd")) == 0)
			mini_cd(args, &data);
		else if (ft_strncmp(args[0], "env", ft_strlen("env")) == 0)
			mini_env(data.envvar);
		else
			commands(args, envp);
		free_array(args);
	}
	return (0);
}

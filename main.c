#include "mini.h"

char	*get_pathname(void)
{
	char	*pwd;
	char	*result;
	int		i;

	pwd = getcwd(NULL, 0);
	if (!pwd)
		return (ft_strdup("$ "));
	i = 0;
	while (pwd[i])
		i++;
	while (i > 0 && pwd[--i] != '/')
		(void)pwd;
	if (i > 0)
		pwd[--i] = '~';
	result = ft_strjoin_free(ft_strdup(pwd + i), "$ ");
	free(pwd);
	return (result);
}

int main(int ac, char **av, char **envp)
{
	char	*input;
	char	**args;
	char	*pwd;
	t_mini	data;

	ft_bzero(&data, sizeof(data));
	data.envvar = copy_envvar(envp);
	data.envvar_export = copy_envvar(envp);
	sort_var(data.envvar_export);
	data.pwd = getcwd(NULL, 0);
	while(1)
	{
		pwd = get_pathname();
		input = readline(color_to_prompt(pwd));
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
			mini_pwd(&data);
		else if (ft_strncmp(args[0], "cd", ft_strlen("cd")) == 0)
			mini_cd(args, &data);
		else if (ft_strncmp(args[0], "env", ft_strlen("env")) == 0)
			mini_env(data.envvar);
		else if (ft_strncmp(args[0], "export", ft_strlen("export")) == 0)
		{
			if (args[1])
				set_envvar(&data, args[1], args[2], 1);
			else
				mini_export(data.envvar_export);
		}
		else
			commands(args, envp);
		free_array(args);
	}
	return (0);
}

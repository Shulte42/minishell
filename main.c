#include "mini.h"

int main(int ac, char **av, char **envp)
{
	char	*input;
	char	*pwd;
	char	**args;
	t_mini	data;

	ft_bzero(&data, sizeof(data));
	data.envvar = create_lst_envvar(envp);
	data.envvar_export = create_lst_export(&data);
	sort_var(data.envvar_export);
	data.pwd = getcwd(NULL, 0);
	while(1)
	{
		pwd = color_to_prompt(get_pathname());
		input = readline(pwd);
		if (!input || !*input)
		{
			free(input);
			continue ;
		}
		add_history(input);
		args = ft_split(input, ' ');
		free(input);
		free(pwd);
		if (ft_strncmp(args[0], "exit", ft_strlen("exit")) == 0)
			{
				free_lst(data.envvar);
				free_lst(data.envvar_export);
				free_array(args);
				free(data.pwd);
				if (data.old_pwd)
					free(data.old_pwd);
				break ;
			}
		else if (ft_strncmp(args[0], "echo", ft_strlen("echo")) == 0)
			mini_echo(args, 1);
		else if(ft_strncmp(args[0], "pwd",ft_strlen("pwd")) == 0)
			mini_pwd(&data);
		else if (ft_strncmp(args[0], "cd", ft_strlen("cd")) == 0)
			cd(&data, args);
		else if (ft_strncmp(args[0], "env", ft_strlen("env")) == 0)
			mini_env(data.envvar);
		else if (ft_strncmp(args[0], "export", ft_strlen("export")) == 0)
		{
			if (args[1])
				set_envvar(&data, args[1], args[2], 1);
			else
				print_export(&data);
		}
		else
			commands(args, envp);
		free_array(args);
	}
	return (0);
}

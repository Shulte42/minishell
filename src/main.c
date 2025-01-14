#include "../mini.h"

int main(int ac, char **av, char **envp)
{
	char	*input;
	char	*expanded_input;
	char	*pwd;
	char	**args;
	t_mini	data;

	(void)av;
	(void)ac;
	ft_bzero(&data, sizeof(data));
	data.envvar = create_lst_envvar(envp);
	data.envvar_export = create_lst_export(&data);
	sort_var(data.envvar_export);
	while(1)
	{
		pwd = color_to_prompt(get_pathname());
		input = readline(pwd);
		free(pwd);
		if (!input || !*input)
		{
			free(input);
			continue ;
		}
		add_history(input);
		expanded_input = expand_envvar(&data, input);
		free(input);
		input = expanded_input;
		args = ft_split(input, ' ');
		free(input);
		if (ft_strncmp(args[0], "exit", ft_strlen(args[0])) == 0)
			{
				free_exit(&data);
				free_array(args);
				return (0);
			}
		else if (ft_strncmp(args[0], "echo", ft_strlen(args[0])) == 0)
			mini_echo(args, 1);
		else if(ft_strncmp(args[0], "pwd", ft_strlen(args[0])) == 0)
			mini_pwd(&data);
		else if (ft_strncmp(args[0], "cd", ft_strlen(args[0])) == 0)
			cd(&data, args);
		else if (ft_strncmp(args[0], "env", ft_strlen(args[0])) == 0)
			mini_env(data.envvar);
		else if (ft_strncmp(args[0], "unset", ft_strlen(args[0])) == 0)
			unset(&data, args);
		else if (ft_strncmp(args[0], "export", ft_strlen(args[0])) == 0)
		{
			if (args[1])
				set_envvar(&data, args[1], args[2], 1);
			else
				print_export(&data);
		}
		else
			commands(&data, args, envp);
		free_array(args);
	}
	return (0);
}

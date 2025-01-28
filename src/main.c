#include "../inc/libs.h"

t_shell *ft_start_shell(void)
{
	static t_shell shell;
	return (&shell);
}

bool    ft_get_input(t_shell *shell)
{
	char	*input;
	char	*pwd;
	
	pwd = color_to_prompt(get_pathname());
	input = readline(pwd);
	if (input == NULL)
		return (false); //todo: lidar com crtl D
	if (input[0] == 0)
	{
		return (false);
		free(input);
	}
	if (input)
	{
		add_history(input);
		shell->input = ft_strdup(input);
		free(input);
	}
	return (true);
}

int	ainput(t_shell *data)
{
	char	**input;

	input = ft_split(data->input, ' ');
	if (!input)
		return (1);
	if (ft_strcmp(input[0], "env") == 0)
		mini_env(data->envvar);
	else if (ft_strcmp(input[0], "export") == 0)
		print_export(data);
	else if (ft_strcmp(input[0], "exit") == 0)
		return (1);
	else
		commands(data, input);
	return (0);
}

static void loop_those_shells(t_shell *minishell)
{
	while (1)
	{
		if(ft_get_input(minishell))
		{
			if (ainput(minishell))
				break ;
			// if (ft_strncmp(minishell->input, "exit", ft_strlen(minishell->input)) == 0)
			// {
			// 	ft_clean_exit(minishell);
			// 	break;
			// }
			// ft_input_analizes(minishell);
		}
	}
}

int main(int ac, char **av, char **envp)
{
	t_shell	*data;

	if (ac != 1)
	{
		printf("Usage: ./minishell\n");
		return (1);
	}
	(void)av;
	data = ft_start_shell();
	data->envvar = create_lst_envvar(envp);
	data->envvar_export = create_lst_export(data);
	sort_var(data->envvar_export);
	sort_var(data->envvar);
	set_shlvl(data);
	set_questionvar(data);
	loop_those_shells(data);
	free_exit(data);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <bruda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:47:54 by shulte            #+#    #+#             */
/*   Updated: 2025/01/07 09:49:48 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libs.h"

t_shell *ft_start_shell(void)
{
	static t_shell shell;
	return (&shell);
}

bool    ft_get_input(t_shell *shell)
{
	char *input;
	
	input = readline("minishell: ");
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
static void loop_those_shells(t_shell *minishell)
{
	while (1)
	{
		if(ft_get_input(minishell))
		{
			ft_input_analizes(minishell);
		}
	}
}

int main(int argc, char **argv, char **env)
{
	char *cwd;
	t_shell *shell;
	
	(void)argc;
	(void)argv;
	shell = ft_start_shell();
	shell->envvars = ft_envvar_list(env);
	loop_those_shells(shell);
	free(shell->input);
	cwd = getcwd(NULL, 0);
	if (cwd != NULL)
	{
		printf("diretorio atual:%s.\n", cwd);
		free(cwd);
	}
	else
		printf("getcwd() error");
	return (0);
}
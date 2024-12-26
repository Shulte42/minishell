/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shulte <shulte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:47:54 by shulte            #+#    #+#             */
/*   Updated: 2024/12/26 16:04:54 by shulte           ###   ########.fr       */
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
	(void)env;
	(void)argv;
	shell = ft_start_shell();
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
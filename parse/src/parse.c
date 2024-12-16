/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shulte <shulte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:47:54 by shulte            #+#    #+#             */
/*   Updated: 2024/12/16 14:09:32 by shulte           ###   ########.fr       */
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
		shell->input = ft_strdup(input);
		free(input);
	}
	return (true);
}

int main(int argc, char **argv, char **env)
{
	char *cwd;
	t_shell *shell;
	
	(void)argc;
	(void)env;
	(void)argv;
	shell = ft_start_shell();
	ft_get_input(shell);
	printf("input :%s.\n", shell->input);
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
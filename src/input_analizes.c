/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_analizes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shulte <shulte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:18:15 by shulte            #+#    #+#             */
/*   Updated: 2025/01/22 14:52:29 by shulte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libs.h"

bool	ft_check_piperedir(char	c)
{
	if (c == '|' || c == '<' || c == '>')
		return (true);
	return (false);
}

int	ft_c_piperedir(char	*str)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (ft_check_piperedir(str[i]))
			count++;
		i++;
	}
	return (count);
}

void    ft_space_piperedir(t_shell  *shell)
{
	char    *input_spaced;
	int     z;
	int		i;
	
	i = 0;
	z = 0;
	input_spaced = ft_calloc(ft_strlen(shell->input) + (ft_c_piperedir(shell->input) * 2) + 1, sizeof(char));
	while (shell->input[i])
	{
		if (ft_inside_quotes(shell->input, i) == 0 && ft_check_piperedir(shell->input[i]))
			{
				input_spaced[z++] = ' ';
				input_spaced[z] = shell->input[i];
				if (shell->input[i + 1] == shell->input[i])
				{
					input_spaced[++z] = shell->input[++i];
					input_spaced[++z] = ' ';
 				}
				else if (shell->input[i + 1] != shell->input[i] && shell->input[i + 1])
					input_spaced[++z] = ' ';
			}
		else
			input_spaced[z] = shell->input[i];
		i++;
		z++;
	}
	input_spaced[z] = '\0';
	free(shell->input);
	shell->input = input_spaced;
	printf("input spaced:%s\n", shell->input);
}

void    ft_parsing_loop(t_shell *shell)
{
	if (ft_quote_checker(shell->input))  
	{
		shell->input = expand_envvar(shell, shell->input);
		ft_space_piperedir(shell);
		ft_quote_handle(shell);
		ft_tokenization(&shell);
		// printf("token:%s\n", shell->tokens->content);//SEGFAULT
	}
}

void    ft_input_analizes(t_shell *data)
{
	ft_parsing_loop(data);
}

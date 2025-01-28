/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_analizes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shulte <shulte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:18:15 by shulte            #+#    #+#             */
/*   Updated: 2025/01/28 13:15:44 by shulte           ###   ########.fr       */
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

// static void add_space_around_piperedir(char	*input, char *input_spaced, int *i, int *z)
// {
// 	if (ft_inside_quotes(input, *i) == 0 && ft_check_piperedir(input[*i]))
	// {
	// 	input_spaced[(*z)++] = ' ';
	// 	input_spaced[*z] = input[*i];
	// 	if (input[*i + 1] == input[*i])
	// 	{
	// 		input_spaced[++(*z)] = input[++(*i)];
	// 		input_spaced[++(*z)] = ' ';
	// 	}
	// 	else if (input[*i + 1] != input[(*i)] && input[*i + 1])
	// 		input_spaced[++(*i)] = ' ';
	// }
	// else
	// 	input_spaced[*z] = input[*i];
// }

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
}

/* funcao simples para verificar a lista de tokens */

void	print_token_lst(t_tokens *lst)
{
	t_tokens	*current;
	int			i;

	current = lst;
	i = 1;
	while(current)
	{
		printf("Token %d : %s\n", i, current->content);
		i++;
		current = current->next;
	}
}

void    ft_parsing_loop(t_shell *shell)
{
	if (ft_quote_checker(shell->input))  
	{
		shell->input = expand_envvar(shell, shell->input);
		ft_space_piperedir(shell);
		// ft_quote_handle(shell);
		ft_tokenization(shell);
		print_token_lst(shell->tokens);/* chamada para funcao que verifica a lista */
		// printf("token:%s\n", shell->tokens->content);//SEGFAULTexit
	}
}

void    ft_input_analizes(t_shell *data)
{
	ft_parsing_loop(data);
}

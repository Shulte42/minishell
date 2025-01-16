/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <bruda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:15:41 by bruda-si          #+#    #+#             */
/*   Updated: 2025/01/16 15:14:18 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libs.h"

int	ft_inside_quotes(char	*str, int index)
{
	char	c;

	c = 0;
	if (!str)
		return (0);
	while (*str && index--)
	{
		if (!c)
		{
			if (*str == '\'' || *str == '\"')
				c = *str;
		}
		else if (c == *str)
			c = 0;
		str++;
	}
	if (c == *str)
		c = 0;
	return ((c == '\'') + ((c == '\"') * 2));
}

void    ft_quote_handle(t_shell *shell)
{
	char    *input;
	int   	start;
	char    *str_quotes;
	char	quote;
	int     i;

	start = 0;
	input = ft_strdup(shell->input);
	quote = 0;
	i = 0;
	printf("quote handler\n");
	while (input[i])
	{
		if (input[i] == '"' || input[i] == '\'')
		{
			if (quote == 0)
			{
				start = i;
				quote = input[i];
			}
			else if (quote == input[i])
			{
				// if (quote == '\'')
				// 	shell->tokens->single_qoutes = true;
				// if (quote == '"')
				// 	shell->tokens->double_quotes = true;
				str_quotes = ft_strndup(&input[start + 1], (i - (start + 1)));
				printf("str_quotes:%s\n", str_quotes);
			}
			
		}
		i++;
	}
	free(input);
}
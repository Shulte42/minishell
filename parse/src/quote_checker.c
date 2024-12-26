/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shulte <shulte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:32:57 by shulte            #+#    #+#             */
/*   Updated: 2024/12/26 16:08:45 by shulte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libs.h"

static int match_quotes(const char *input)
{
	char c;
	
	c = 0;
	while (*input != '\0')
	{
		if (*input == '"' || *input == '\'')
		{
			if (c == 0)
				c = *input;
			else if (c == *input)
				c = 0;
		}
		input++;
	}
	return (c);
}


bool ft_quote_checker(char *input)
{
	if(match_quotes(input))
		{
			printf("unmatched quotes (falta terminar!!!)\n");//todo; funcao propria pra lidar com errors
			return (false);
		}
	else
		return (true);
	
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shulte <shulte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:32:57 by shulte            #+#    #+#             */
/*   Updated: 2024/12/29 13:43:20 by shulte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libs.h"

static bool space_trim(char *input, char *temp)
{
	static int	x = 0;
	static int	z = 0;
	char		c;

	if (!input[x])
		return (false);
	while (input[x] && input[x] != '\'' \
	&& input[x] != '\"' && !ft_isspace(input[x]))
}

static char *trim_hub(char *input)
{
	char *temp;
	
	temp = ft_calloc(ft_strlen(input) + 1, sizeof(char));
	if (!temp)
		return (NULL);
	while (space_trim(input, temp) == false)
		(void)0;
	return (temp);
}

static int input_cleaner(char *input)
{
	char trim;

	if (!input)
		return (-1);
	trim = trim_input(input);
	if (!trim)
		return (-1);
	ft_strlcpy(input, trim, ft_strlen(trim) + 1);
	free(trim);
	return (0);
}
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
	if (input_cleaner(input) == -1)
	{
		printf("Fail to allocat memory (falta terminar!!!)\n");//todo; funcao propria pra lidar com errors
		return (false);
	}
	return (true);
}
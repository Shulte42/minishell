/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiz-dos <luiz-dos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:32:57 by shulte            #+#    #+#             */
/*   Updated: 2025/01/14 14:39:13 by luiz-dos         ###   ########.fr       */
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shulte <shulte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:15:41 by bruda-si          #+#    #+#             */
/*   Updated: 2025/01/28 15:24:55 by shulte           ###   ########.fr       */
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

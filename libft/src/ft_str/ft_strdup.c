/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <bruda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:05:59 by bruda-si          #+#    #+#             */
/*   Updated: 2025/01/15 11:19:55 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../../../inc/libs.h"

char	*ft_strdup(const char *s)
{
	char	*n_str;

	n_str = (char *)malloc(ft_strlen(s) + 1);
	if (!n_str)
		return (NULL);
	ft_memcpy((void *)n_str, (const void *)s, ft_strlen(s));
	n_str[ft_strlen(s)] = '\0';
	return (n_str);
}

// char *ft_strndup(char *list)
// {
// 	char	*n_str;
	
// 	n_str = (char *)malloc(ft_strnlen(list) + 1);
// 	if (!n_str)
// 		return (NULL);
// 	ft_memcpy((void *)n_str, (const void *)list, ft_strnlen(list));
// 	n_str[ft_strnlen(list)] = '\0';
// 	return (n_str);
// }

char	*ft_strndup(const char *s, size_t n)
{
	char	*dup;
	size_t	i;

    if (!s)
		return (NULL);
	dup = malloc(n + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i] && i < n)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
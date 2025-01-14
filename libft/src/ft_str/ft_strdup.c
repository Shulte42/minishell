/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiz-dos <luiz-dos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:05:59 by bruda-si          #+#    #+#             */
/*   Updated: 2025/01/14 14:47:26 by luiz-dos         ###   ########.fr       */
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envvar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <bruda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:13:19 by bruda-si          #+#    #+#             */
/*   Updated: 2025/01/07 11:10:06 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libs.h"

t_envvar    *ft_envvar_list(char **env)
{
	t_envvar    *head;
	t_envvar    *new_node;
	char        **current;

	head = NULL;
	current = env;
	while (*current)
	{
		new_node = ft_calloc(1, sizeof(t_envvar));
		new_node->content = ft_strdup(*current);
		new_node->name = ft_strndup(*current);
		new_node->value = ft_strdup(ft_strchr(*current, '=') + 1);
		ft_envadd_back(&head, new_node);
		current++;
	}
	return (head);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shulte <shulte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:11:29 by bruda-si          #+#    #+#             */
/*   Updated: 2025/01/21 10:13:08 by shulte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libs.h"

void    ft_type_tokens(t_shell *tokens)
{
	t_shell	*node;

	node = tokens;
	while (node->next)
	{
		if(ft_builtins(&node) == 0)
		{
			exec_builtins(node);
		}
	}
}

int	ft_builtins(t_shell	*tokens_node)
{
	if (ft_strcmp(tokens_node->tokens->content, "pwd") == 0)
	{
		mini_pwd(tokens_node);
		return (0);
	}
	
}
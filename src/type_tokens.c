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

#include "../inc/libs.h"

void    ft_set_token_type(t_tokens *tokens)
{
	t_tokens	*node;

	node = tokens;
	while (node->next)
	{
		// if (ft_builtins(&node) == 0)
		// {
		// 	exec_builtins(node);
		// }
	}
}

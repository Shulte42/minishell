/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <bruda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:11:29 by bruda-si          #+#    #+#             */
/*   Updated: 2025/01/15 15:11:35 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libs.h"

void    ft_type_tokens(t_tokens *tokens)
{
	t_tokens    *node;

	while (node->next)
	{
		if(ft_strcmp(node->token, "echo") == 0)
			return;
	}
}
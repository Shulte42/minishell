/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <bruda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:30:06 by bruda-si          #+#    #+#             */
/*   Updated: 2025/01/13 15:40:46 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libs.h"

static void    ft_tokenclear(t_tokens *lst)
{
	t_tokens	*tokens;
	t_tokens	*next;

	tokens = lst;
	while (tokens != NULL)
	{
		next = tokens->next;
		free(tokens->token);
        free(tokens);
		tokens = next;
	}
}

void	ft_clean_exit(t_shell	*minishell)
{
	ft_tokenclear(minishell->tokens);
}
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

void	ft_set_token_type(t_tokens *lst)
{
	t_tokens	*current;

	current = lst;
	while (current)
	{
		if (ft_strcmp(current->content, ">") == 0)
			current->type = REDIR_OUT;
		else if (ft_strcmp(current->content, ">>") == 0)
			current->type = APPEND_OUT;
		else if (ft_strcmp(current->content, "<") == 0)
			current->type = REDIR_IN;
		else if (ft_strcmp(current->content, "<<") == 0)
			current->type = HEREDOC;
		else if (ft_strcmp(current->content, "|") == 0)
			current->type = PIPE;
		else if (!current->prev || (current->prev->type >= REDIR_OUT))
			current->type = CMD;
		else
			current->type = ARG;
		current = current->next;
	}
}

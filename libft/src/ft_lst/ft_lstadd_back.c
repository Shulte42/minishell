/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiz-dos <luiz-dos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 14:59:46 by bruda-si          #+#    #+#             */
/*   Updated: 2025/01/14 14:42:07 by luiz-dos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../../../inc/libs.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*curr;

	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	curr = ft_lstlast(*lst);
	curr->next = new;
}

void	ft_envadd_back(t_var **lst, t_var *new)
{
	t_var	*curr;

	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	curr = ft_envlast(*lst);
	curr->next = new;
}

void	ft_tokenadd_back(t_tokens **lst, t_tokens *new)
{
	t_tokens	*curr;

	if(!lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	curr = ft_tokenlast(*lst);
	curr->next = new;
}
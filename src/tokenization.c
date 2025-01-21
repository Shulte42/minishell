/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shulte <shulte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:05:22 by bruda-si          #+#    #+#             */
/*   Updated: 2025/01/21 10:13:17 by shulte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libs.h"

char *ft_gettoken(char  *input, int delim, bool fst)
{
	static  char    *static_str = NULL;
	char    *token;

	if (static_str == NULL && fst)
		static_str = input;
	if (static_str == NULL)
		return (NULL);
	while (*static_str && *static_str == delim)
		static_str++;
	if  (*static_str == '\0')
		return (NULL);
	token = static_str;
	while (*static_str && *static_str != delim)
		static_str++;
	if (*static_str)
	{
		*static_str = '\0';
		static_str++;
	}
	else
		static_str = NULL;
	return (ft_strdup(token));
}

t_tokens	*ft_addtoken(char *token)
{
	t_tokens	*head;
	t_tokens	*new_node;

	head = NULL;
	new_node = ft_calloc(1, sizeof(t_tokens));
	new_node->content = token;
	ft_tokenadd_back(&head, new_node);
	return (head);
}

void    ft_tokenization(t_shell *shell)
{
	char    *input;
	char    *token;
	t_tokens    *tokens;

	tokens = NULL;
	input = shell->input;
	printf("input antes de gettoken:%s\n", input);
	token = ft_gettoken(input, 32, true);
	printf("token1:%s\n", token);
	while (token != NULL)
	{
		tokens = ft_addtoken(token);
		token = ft_gettoken(input, 32, false);
		printf("struct token:%s\n", tokens->content);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <bruda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:05:22 by bruda-si          #+#    #+#             */
/*   Updated: 2025/01/13 14:13:00 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libs.h"

char *ft_gettoken(char  *input, int delim)
{
	static  char    *static_str;
	char    *token;
	// static	char	*tmp;

	if (input != NULL)
		static_str = input;
	if (static_str == NULL)
		return (NULL);
	while (*static_str && *static_str == delim)
		static_str++;
	if  (*static_str == '\0')
		return (NULL);
	printf("static str:%s\n", static_str);
	token = static_str;
	// printf("token:%s\n", token);
	while (*static_str && *static_str != delim)
		static_str++;
	if (*static_str)
	{
		*static_str = '\0';
		static_str++;
	}
	else
		static_str = NULL;
	printf("gettoken:%s\n", token);
	return (token);
}

t_tokens	*ft_addtoken(char *token)
{
	t_tokens	*head;
	t_tokens	*new_node;

	head = NULL;
	new_node = ft_calloc(1, sizeof(t_tokens));
	new_node->token = token;
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
	token = ft_gettoken(input, 32);
	printf("token1:%s\n", token);
	token = ft_gettoken(input, 32);
	printf("token2:%s\n", token);
	// while (token != NULL)
	// {
	// 	tokens = ft_addtoken(token);
	// 	token = ft_gettoken(input, 32);
	// 	printf("struct token:%s\n", tokens->token);
	// }
}

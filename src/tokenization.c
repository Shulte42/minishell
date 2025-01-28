/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <bruda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:05:22 by bruda-si          #+#    #+#             */
/*   Updated: 2025/01/13 14:58:39 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libs.h"

// char *ft_gettoken(char  *input, int delim, bool fst)
// {
// 	static  char    *static_str = NULL;
// 	char    *token;

// 	if (static_str == NULL && fst)
// 		static_str = input;
// 	if (static_str == NULL)
// 		return (NULL);
// 	while (*static_str && *static_str == delim)
// 		static_str++;
// 	if  (*static_str == '\0')
// 		return (NULL);
// 	token = static_str;
// 	while (*static_str && *static_str != delim)
// 		static_str++;
// 	if (*static_str)
// 	{
// 		*static_str = '\0';
// 		static_str++;
// 	}
// 	else
// 		static_str = NULL;
// 	return (ft_strdup(token));
// }

char *ft_gettoken(char *input, int delim, bool fst)
{
	static char *static_str = NULL;
	char *token;
	char quote = '\0';

	if (static_str == NULL && fst)
		static_str = input;
	if (static_str == NULL)
		return (NULL);
	while (*static_str && *static_str == delim)
		static_str++;
	if (*static_str == '\0')
		return (NULL);
	token = static_str;
	while (*static_str && (*static_str != delim || quote != '\0'))
	{
		if (*static_str == '\'' || *static_str == '\"')
		{
			if (quote == '\0')
				quote = *static_str;
			else if (quote == *static_str)
				quote = '\0';
		}
		static_str++;
	}
	if (*static_str)
	{
		*static_str = '\0';
		static_str++;
	}
	else
		static_str = NULL;
	return (ft_strdup(token));
}

void    ft_tokenization(t_shell *shell)
{
	char        *input;
	char        *token;
	t_tokens    *node;
	t_tokens    *head;

	input = shell->input;
	token = ft_gettoken(input, ' ', true);
	head = NULL;
	node = NULL;
	while (token != NULL)
	{
		node = ft_calloc(1, sizeof(t_tokens));
		node->content = token;
		node->type = -1;
		node->single_qoutes = false;
		node->double_quotes = false;
		ft_tokenadd_back(&head, node);
		token = ft_gettoken(input, ' ', false);
	}
	shell->tokens = head;
}

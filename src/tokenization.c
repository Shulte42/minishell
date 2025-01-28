/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shulte <shulte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:05:22 by bruda-si          #+#    #+#             */
/*   Updated: 2025/01/28 14:04:11 by shulte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libs.h"

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

t_tokens *ft_addtoken(char *token)
{
    t_tokens *head;
    t_tokens *new_node;

    head = NULL;
    new_node = ft_calloc(1, sizeof(t_tokens));
    new_node->content = token;
    ft_tokenadd_back(&head, new_node);
    return (head);
}

/* nessa versao nao precisa da funcao ft_addtoken */
void ft_tokenization(t_shell *data)
{
    char *input;
    char *token;
    t_tokens *node; // temp para armazenar o token atual
    t_tokens *head; // cabeca da lista

    input = data->input;
    token = ft_gettoken(input, ' ', true);
    head = NULL;
    node = NULL;
    while (token != NULL)
    {
        node = ft_calloc(1, sizeof(t_tokens));
        node->content = token;
        /* abaixo so inicializo os valores */
        node->type = -1;
        node->single_qoutes = false;
        node->double_quotes = false;
        ft_set_token_type(node);
        ft_tokenadd_back(&head, node); // adiciona o token atual ao fim da lista
        token = ft_gettoken(input, ' ', false);
    }
    data->tokens = head; // ponteiro tokens recebe a cabeca da lista
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shulte <shulte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:05:22 by bruda-si          #+#    #+#             */
/*   Updated: 2025/01/08 14:53:01 by shulte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libs.h"

char *ft_gettoken(char  *input, int delim)
{
    static  char    *static_str;
    char    *token;

    if (input != NULL)
        static_str = input;
    if (static_str == NULL)
        return (NULL);
    while (*static_str && ft_strchr(static_str, delim))
        static_str++;
    if  (*static_str == '\0')
        return (NULL);
    token = static_str;
    while (*static_str && !ft_strchr(static_str, delim))
        static_str++;
    if (*static_str)
    {
        *static_str = '\0';
        static_str++;
    }
    else
        static_str = NULL;
    return (token);
}

void    ft_tokenization(t_shell *shell)
{
    char    *input;
    char    *token;
    // t_tokens    *tokens;

    // tokens = NULL;
    input = shell->input;
    token = ft_gettoken(input, 32);
    printf("token:%s\n", token);
    // while (token != NULL)
    // {
    //     // ft_addtoken(&tokens, token);
    //     token = ft_gettoken(input, 32);
    // }
    shell->tokens->token = token;
}

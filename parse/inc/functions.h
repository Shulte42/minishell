/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <bruda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:56:29 by shulte            #+#    #+#             */
/*   Updated: 2025/01/13 15:40:22 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

#include "structs.h"

void    ft_input_analizes(t_shell *shell);
bool ft_quote_checker(char *input);
t_envvar    *ft_envvar_list(char **env);
char *ft_gettoken(char  *input, int delim, bool fst);
void    ft_tokenization(t_shell *shell);
void	ft_clean_exit(t_shell	*minishell);

#endif
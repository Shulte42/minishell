/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shulte <shulte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:56:29 by shulte            #+#    #+#             */
/*   Updated: 2025/01/08 14:31:42 by shulte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

#include "structs.h"

void    ft_input_analizes(t_shell *shell);
bool ft_quote_checker(char *input);
t_envvar    *ft_envvar_list(char **env);
char *ft_gettoken(char  *input, int delim);
void    ft_tokenization(t_shell *shell);


#endif
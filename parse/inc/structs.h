/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shulte <shulte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:38:35 by shulte            #+#    #+#             */
/*   Updated: 2024/12/09 17:03:48 by shulte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct envvar_struct
{
    char    *content;
    char    *name;
    char    *value;
    struct envvar_struct *next;
    struct envvar_struct *prev;
}   t_envvar;

typedef struct s_shell
{
    char    *input;
    t_envvar    *envvars;
}   t_shell;


#endif
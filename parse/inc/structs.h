/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <bruda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:38:35 by shulte            #+#    #+#             */
/*   Updated: 2025/01/07 14:23:22 by bruda-si         ###   ########.fr       */
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

typedef struct builtins_struct
{
    
}   t_builtins;

typedef struct s_shell
{
    char    *input;
    t_envvar    *envvars;
}   t_shell;


#endif
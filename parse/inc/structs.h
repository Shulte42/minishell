/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <bruda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:38:35 by shulte            #+#    #+#             */
/*   Updated: 2025/01/14 10:51:29 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct envvar_struct
{
	char    *content;
	char    *name;
	char    *value;
	struct envvar_struct	*next;
	struct envvar_struct	*prev;
}   t_envvar;

typedef struct argumments_struct
{
	char    *arg;
	struct	arguments_struct	*next;
	struct	arguments_struct	*prev;
}   t_args;


typedef struct builtins_struct
{
	
}   t_builtins;

typedef struct tokens_struct
{
	char	*token;
	int		type;
	struct tokens_struct	*next;
	struct tokens_struct	*prev;
}	t_tokens;


typedef struct s_shell
{
	char        *input;
	t_envvar    *envvars;
	t_args      *args;
	t_builtins	*builtins;
	t_tokens	*tokens;
	struct	s_shell	*next;
	struct	s_shell	*prev;
}   t_shell;


#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shulte <shulte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:38:35 by shulte            #+#    #+#             */
/*   Updated: 2025/01/21 15:16:45 by shulte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct		s_var
{
	char			*content;
	char			*name;
	char			*value;
	bool			env;
	bool			exp;
	struct s_var	*next;
	struct s_var	*prev;
}					t_var;

typedef struct argumments_struct
{
	char    *arg;
	struct	arguments_struct	*next;
	struct	arguments_struct	*prev;
}   t_args;


typedef struct builtins_struct
{
	
}   t_builtins;

typedef enum	e_builtins
{
	B_ECHO,
	CD,
	PWD,
	EXPORT,
	UNSET,
	ENV,
	EXIT,
}				t_enum;

typedef struct				tokens_struct
{
	char					*content;
	int						type;
	bool					double_quotes;
	bool					single_qoutes;
	struct tokens_struct	*next;
	struct tokens_struct	*prev;
}							t_tokens;


typedef struct s_shell
{
	char        *input;
	int			return_status; // $?
	t_var		*envvar;
	t_var		*envvar_export;
	t_args      *args;
	t_builtins	*builtins;
	t_tokens	*tokens;
	struct	s_shell	*next;
	struct	s_shell	*prev;
}  				t_shell;


#endif
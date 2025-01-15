/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: bruda-si <bruda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:38:35 by shulte            #+#    #+#             */
/*   Updated: 2025/01/15 11:00:31 by bruda-si         ###   ########.fr       */
=======
/*   By: luiz-dos <luiz-dos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:38:35 by shulte            #+#    #+#             */
/*   Updated: 2025/01/14 15:41:04 by luiz-dos         ###   ########.fr       */
>>>>>>> 2c0ba6a32a712db57eb291ed20e76b8ddf2ad594
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
	EXIT
<<<<<<< HEAD
}				t_enum;
=======
};
>>>>>>> 2c0ba6a32a712db57eb291ed20e76b8ddf2ad594

typedef struct				tokens_struct
{
	char					*token;
	int						type;
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
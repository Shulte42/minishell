/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <bruda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:38:35 by shulte            #+#    #+#             */
/*   Updated: 2025/01/15 11:17:03 by bruda-si         ###   ########.fr       */
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

typedef struct	s_command
{
	char				*cmd;
	char				**args;
	char				*infile;
	char				*outfile;
	char				*heredoc_delim;
	bool				has_heredoc;
	int					heredoc_fd;
	pid_t				heredoc_pid;
	int					append; // 1 se ">>", 0 se ">", -1 se nenhum 
	bool				has_pipe; // true se tiver um pipe
	int					pipe_fd[2];
	struct s_command	*next;
}						t_command;

enum e_types
{
	CMD,
	ARG,
	FILENAME,
	DELIM,
	PIPE,
	HEREDOC, // <<
	APPEND_OUT, // >>
	REDIR_OUT, // >
	REDIR_IN // <
};

typedef struct				s_tokens
{
	char					*content;
	int						type;
	bool					double_quotes;
	bool					single_qoutes;
	struct s_tokens	*next;
	struct s_tokens	*prev;
}							t_tokens;


typedef struct s_shell
{
	char        *input;
	int			signal;
	int			return_status; // $?
	char		**ev_array;
	t_var		*envvar;
	t_var		*envvar_export;
	t_args      *args;
	t_builtins	*builtins;
	t_tokens	*tokens;
	t_command	*commands;
	struct	s_shell	*next;
	struct	s_shell	*prev;
}  				t_shell;

#endif
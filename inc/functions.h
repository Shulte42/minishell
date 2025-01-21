/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shulte <shulte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:56:29 by shulte            #+#    #+#             */
/*   Updated: 2025/01/21 16:30:14 by shulte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

#include "structs.h"

/* tokens */
void    ft_input_analizes(t_shell *data);
bool    ft_quote_checker(char *input);
char    *ft_gettoken(char  *input, int delim, bool fst);
void    ft_tokenization(t_shell *data);
void    ft_clean_exit(t_shell *minishell);
void    ft_type_tokens(t_shell *tokens);
void    ft_quote_handle(t_shell *shell);
int	ft_inside_quotes(char	*str, int index);
bool	ft_check_piperedir(char	c);
int	ft_c_piperedir(char	*str);
void    ft_space_piperedir(t_shell  *shell);
void    ft_type_tokens(t_shell *tokens);

/* execute commands */
void	commands(t_shell	*data, char **args, char **envp);
char	*get_command_path(char *cmd, char **envp);
void	execute_command(char **cmd, char **env_var);
char	**envvar_array(t_var *lst);

/* utils */
int		only_space(char *str);
int		open_file(char *file, int flags, int mode);
char	*color_to_prompt(char *prompt);
int		check_envp(char **envp);
bool	check_options(char *option);

char	*ft_strjoin_free(const char *s1, const	char *s2);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strcat(char *dest, char *src);
char	*ft_strdup_two(const char *s, char c);

/* redirect */
void 	redirect_input(char *file);
void	redirect_output(char *file);
void	redirect_output_append(char *file);
void	redirect_heredoc(char *delimiter);

void	mini_echo(char	**args, int fd);
void	mini_pwd(t_shell *data);
void	mini_env(t_var *lst);

/* export */
void	print_export(t_shell *data);
void	sort_var(t_var *lst);
void	swap_nodes(t_var *current, t_var *next);
t_var	*create_lst_export(t_shell *data);
t_var   *copy_var_node(t_var *envvar);

/* dolar */
char	*expand_envvar(t_shell *data, char *input);
void	expand_envvar_two(char *expanded, char *var_value, int *j);
char	*extract_var_name(char *input, int *index);
/* unset */
void	unset(t_shell *data, char **args);
void	remove_envvar(t_var **lst, t_var *envvar);

/* cd */
void	cd(t_shell *data, char **args);
void	change_dir(char *dir, int flag_free, t_shell *data);
void	update_pwd(t_shell *data, char *dir);
char	*get_dir(char *arg, int *flag_free, t_shell *data);

/* lst */
t_var	*create_lst_envvar(char **envp);
void	add_var_back(t_var **lst, t_var *node);

t_var	*find_envvar(t_var *lst, char *name);
char	*get_value(t_shell *data, char *name);
char	*get_pathname(void);

/* set env*/
void    set_envvar(t_shell *data, char *name, char *value, int flag);
void    add_new_envvar(t_var *lst, char *name, char *value, int flag);
void    update_envvar(t_var *envvar, char *name, char *value);
char    *create_envvar_content(char *name, char *value);

/* free*/
void	free_array(char **array);
void	free_lst(t_var *lst);
void	free_exit(t_shell *data);

#endif /* FUNCTIONS_H */
#ifndef MINI_H
#define MINI_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>

# define CYAN "\033[1;36m"
# define RESET "\033[0m"

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


typedef struct	s_mini
{
	t_var		*envvar;
	t_var		*envvar_export;
}				t_mini;

/* execute commands */
void	commands(t_mini	*data, char **args, char **envp);
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
char	*ft_strndup(const char *s, size_t n);

/* redirect */
void 	redirect_input(char *file);
void	redirect_output(char *file);
void	redirect_output_append(char *file);
void	redirect_heredoc(char *delimiter);

void	mini_echo(char	**args, int fd);
void	mini_pwd(t_mini *data);
void	mini_env(t_var *lst);

/* export */
void	print_export(t_mini *data);
void	sort_var(t_var *lst);
void	swap_nodes(t_var *current, t_var *next);
t_var	*create_lst_export(t_mini *data);
t_var   *copy_var_node(t_var *envvar);

/* dolar */
char	*expand_envvar(t_mini *data, char *input);
void	expand_envvar_two(char *expanded, char *var_value, int *j);
char	*extract_var_name(char *input, int *index);
/* unset */
void	unset(t_mini *data, char **args);
void	remove_envvar(t_var **lst, t_var *envvar);

/* cd */
void	cd(t_mini *data, char **args);
void	change_dir(char *dir, int flag_free, t_mini *data);
void	update_pwd(t_mini *data, char *dir);
char	*get_dir(char *arg, int *flag_free, t_mini *data);

/* lst */
t_var	*create_lst_envvar(char **envp);
void	add_var_back(t_var **lst, t_var *node);

t_var	*find_envvar(t_var *lst, char *name);
char	*get_value(t_mini *data, char *name);
char	*get_pathname(void);

/* set env*/
void    set_envvar(t_mini *data, char *name, char *value, int flag);
void    add_new_envvar(t_var *lst, char *name, char *value, int flag);
void    update_envvar(t_var *envvar, char *name, char *value);
char    *create_envvar_content(char *name, char *value);

/* free*/
void	free_array(char **array);
void	free_lst(t_var *lst);
void	free_exit(t_mini *data);

#endif /* MINI_H */
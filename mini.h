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
	struct s_var	*next;
	struct s_var	*prev;
}					t_var;


typedef struct	s_mini
{
	char		*pwd;
	char		*old_pwd;
	t_var		*envvar;
	t_var		*envvar_export;
}				t_mini;

void	commands(char **args, char **envp);
char	*get_command_path(char *cmd, char **envp);
void	execute_command(char **cmd, char **envp);

void	free_array(char **array);
int		only_space(char *str);
int		open_file(char *file, int flags, int mode);
char	*color_to_prompt(char *prompt);

int		check_envp(char **envp);

char	*ft_strjoin_free(const char *s1, const	char *s2);
char	*ft_strdup_two(const char *s, char c);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strcat(char *dest, char *src);

void 	redirect_input(char *file);
void	redirect_output(char *file);
void	redirect_output_append(char *file);
void	redirect_heredoc(char *delimiter);

void	mini_echo(char	**args, int fd);
void	mini_pwd(t_mini *data);
void	mini_cd(char **args, t_mini	*data);
void	mini_env(t_var *lst);
void	mini_export(t_var *lst);

t_var	*copy_envvar(char **envp);
void	add_var_back(t_var **lst, t_var *node);
void	sort_var(t_var *lst);
void	swap_nodes(t_var *current, t_var *next);

t_var	*find_envvar(t_var *lst, char *name);
char	*get_pathname(void);

#endif /* MINI_H */
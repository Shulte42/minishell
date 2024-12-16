#ifndef MINI_H
#define MINI_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>

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
}				t_mini;

void	commands(char **args, char **envp);
char	*get_command_path(char *cmd, char **envp);
void	execute_command(char **cmd, char **envp);

void	free_array(char **array);
int		only_space(char *str);
int		open_file(char *file, int flags, int mode);

int		check_envp(char **envp);

char	*ft_strjoin_free(const char *s1, const	char *s2);
char	*ft_strndup(const char *s, size_t n);

void 	redirect_input(char *file);
void	redirect_output(char *file);
void	redirect_output_append(char *file);
void	redirect_heredoc(char *delimiter);

void	mini_echo(char	**args, int fd);
void	mini_pwd(void);
void	mini_cd(char **args, t_mini	*data);
void	mini_env(t_var *lst);

t_var	*copy_envvar(char **envp);
void	add_var_back(t_var **lst, t_var *node);


#endif /* MINI_H */
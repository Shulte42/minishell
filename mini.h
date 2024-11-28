#ifndef MINI_H
#define MINI_H

#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>

char	*get_command_path(char *cmd, char **envp);
void	execute_command(char **cmd, char **envp);

void	free_array(char **array);
int		only_space(char *str);

int		check_envp(char **envp);

char	*ft_strjoin_free(const char *s1, const	char *s2);
int		open_file(char *file, int flags, int mode);

void 	redirect_input(char *file);
void	redirect_output(char *file);
void	redirect_output_append(char *file);
void	redirect_heredoc(char *delimiter);


#endif /* MINI_H */
#include "../inc/libs.h"

// int main(int ac, char **av, char **envp)
// {
// 	char	*input;
// 	char    *first_cmd[] = {"ls", "-l", NULL};
//     char	*second_cmd[] = {"grep", "Dec", NULL};
// 	pid_t	pid;
// 	int		fd_pipe[2];

// 	input = readline("Mini> ");
// 	if (!input)
// 		return (1);
// 	if (pipe(fd_pipe) == -1)
// 		return (1);
// 	pid = fork();
// 	if (pid == -1)
// 		return (1);
// 	if (pid == 0)
// 	{
// 		close(fd_pipe[0]);
// 		dup2(fd_pipe[1], STDOUT_FILENO);
// 		close(fd_pipe[1]);
// 		execve("/bin/ls", first_cmd, envp);
// 	}
// 	else
// 	{
// 		wait(NULL);
// 		close(fd_pipe[1]);
// 		dup2(fd_pipe[0], STDIN_FILENO);
// 		close(fd_pipe[0]);
// 		redirect_output_append("output.txt");
// 		execve("/bin/grep", second_cmd, envp);
// 	}
// 	free(input);
// 	return (0);
// }
/*	
	ls -l | grep Nov > output.txt
*/
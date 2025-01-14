#include "../mini.h"

void 	redirect_input(char *file)
{
	int	fd_in;

	fd_in = open_file(file, O_RDONLY, 0);
	if (dup2(fd_in, STDIN_FILENO) == -1)
	{
		perror("Error redirecting input");
		close(fd_in);
		return ;
	}
	close(fd_in);
}

void	redirect_output(char *file)
{
	int	fd_out;

	fd_out = open_file(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (dup2(fd_out, STDOUT_FILENO) == -1)
	{
		perror("Error redirecting output");
		close(fd_out);
		return ;
	}
	close(fd_out);
}

void	redirect_output_append(char *file)
{
	int	fd_out;

	fd_out = open_file(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (dup2(fd_out, STDOUT_FILENO) == -1)
	{
		perror("Error redirecting output");
		close(fd_out);
		return ;
	}
	close (fd_out);
}

void	redirect_heredoc(char *delimiter)
{
	int		fd[2];
	char	buffer[1024];
	ssize_t	bytes_read;

	if (pipe(fd) == -1)
		return (perror("Error creating pipe"));
	while (1)
	{
		write(STDIN_FILENO, "> ", 2);
		bytes_read = read(STDIN_FILENO, buffer, sizeof(buffer) - 1);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		if (ft_strncmp(buffer, delimiter, ft_strlen(delimiter)) == 0
			&& buffer[ft_strlen(delimiter)] == '\n')
			break ;
		write(fd[1], buffer, bytes_read);
	}
	close(fd[1]);
	if (dup2(fd[0], STDIN_FILENO) == - 1)
	{
		close(fd[0]);
		return (perror("Error redirecting heredoc"));
	}
	close(fd[0]);
}

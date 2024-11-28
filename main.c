#include "mini.h"

int main(int ac, char **av, char **envp)
{
	char	*line;

	redirect_heredoc("EOF");
	redirect_output(av[1]);
	while ((line = get_next_line(STDIN_FILENO)))
	{
		write(STDOUT_FILENO, line, ft_strlen(line));
		free(line);
	}
	return (0);
}

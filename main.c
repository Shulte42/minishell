#include "mini.h"

void	mini_echo(char	**args, int fd)
{
	t_bool	flag_nl;
	int		i;

	flag_nl = B_FALSE;
	i = 1;
	if (args[i] && ft_strncmp(args[i], "-n", 2) == 0)
	{
		flag_nl = B_TRUE;
		i++;
	}
	while (args[i])
	{
		ft_putstr_fd(args[i], fd);
		if (args[i + 1])
			ft_putchar_fd(' ', fd);
		i++;
	}
	if (!flag_nl)
		ft_putchar_fd('\n', fd);
}

/*
	echo -n luiz henrique maciel
*/
int main(int ac, char **av, char **envp)
{
	char	*input;
	char	**args;

	input = readline("Mini> ");
	args = ft_split(input, ' ');
	mini_echo(args, 1);
	return (0);
}

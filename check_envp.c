#include "mini.h"

int	check_envp(char **envp)
{
	int	i;

	if (!envp || !*envp)
	{
		printf("environment not found\n");
		return (1);
	}
	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH", 5))
		{
			if (*(envp[i] + 5) != '\0')
				return (0);
			else
			{
				printf("PATH variable is empty\n");
				return (1);
			}
		}
		i++;
	}
	printf("PATH variable not found\n");
	return (1);
}

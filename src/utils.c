#include "../inc/libs.h"

int	only_space(char *str)
{
	int i;

	i = 0;
	while(str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

int	open_file(char *file, int flags, int mode)
{
	int	fd;

	fd = open(file, flags, mode);
	if (fd == -1)
	{
		printf("Error opening %s", file);
		perror(file);
		exit(EXIT_FAILURE);
	}
	return (fd);
}


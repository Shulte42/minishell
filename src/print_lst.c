#include "../inc/libs.h"

/* funcoes apenas para testes */

void	print_token_lst(t_tokens *lst)
{
	t_tokens	*current;
	int			i;

	current = lst;
	i = 1;
	while(current)
	{
		printf("Token %d (type: %d): %s\n", i, current->type, current->content);
		i++;
		current = current->next;
	}
}

void	print_cmd_lst(t_command *lst)
{
	t_command	*current;
	int			i;

	current = lst;
	while (current)
	{
		printf("=================================\n");
		printf("Command name: %s\n", current->cmd);
		if (current->args)
		{
			printf("Args:");
			i = -1;
			while (current->args[++i])
				printf(" %s", current->args[i]);
			printf("\n");
		}
		if (current->infile)
			printf("Infile: %s\n", current->infile);
		if (current->outfile)
			printf("Outfile: %s\n", current->outfile);
		if (current->append != -1)
			printf("Append: %d\n", current->append);
		if (current->is_pipe)
			printf("Pipe: True\n");
		printf("=================================\n");
		printf("\n");
		current = current->next;
	}
}

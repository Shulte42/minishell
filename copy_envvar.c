#include "mini.h"

void	add_var_back(t_var **lst, t_var *node)
{
	t_var	*current;

	if (*lst == NULL)
		*lst = node;
	else
	{
		current = *lst;
		while (current->next != NULL)
			current = current->next;
		current->next = node;
	}
}

t_var	*copy_envvar(char **envp)
{
	char	**current;
	t_var	*node;
	t_var	*head;

	head = NULL;
	current = envp;
	while (*current)
	{
		node = ft_calloc(1, sizeof(t_var));
		node->content = ft_strdup(*current);
		node->name = ft_strndup(*current, ft_strchr(*current, '=') - *current);
		node->value = ft_strdup(ft_strchr(*current, '=') + 1);
		add_var_back(&head, node);
		current++;
	}
	return (head);
}

#include "mini.h"

t_var	*find_envvar(t_var *lst, char *name)
{
	t_var	*current;

	if (!lst || !name)
		return (NULL);
	current = lst;
	while(current)
	{
		if (current->name && ft_strcmp(current->name, name) == 0)
			return (current);
		current = current->next;
	}
	return (NULL);
}

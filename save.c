

// void	add_var_back(t_var **lst, t_var *node)
// {
// 	t_var	*current;

// 	if (*lst == NULL)
// 		*lst = node;
// 	else
// 	{
// 		current = *lst;
// 		while (current->next != NULL)
// 			current = current->next;
// 		current->next = node;
// 		node->prev = current;
// 	}
// }

// t_var	*copy_envvar(char **envp)
// {
// 	char	**current;
// 	t_var	*node;
// 	t_var	*head;

// 	head = NULL;
// 	current = envp;
// 	while (*current)
// 	{
// 		node = ft_calloc(1, sizeof(t_var));
// 		node->content = ft_strdup(*current);
// 		node->name = ft_strdup_two(*current, '=');
// 		node->value = ft_strdup(ft_strchr(*current, '=') + 1);
// 		add_var_back(&head, node);
// 		current++;
// 	}
// 	return (head);
// }

// void	swap_nodes(t_var *current, t_var *next)
// {
// 	char	*content_temp;
// 	char	*name_temp;
// 	char	*value_temp;

// 	content_temp = current->content;
// 	name_temp = current->name;
// 	value_temp = current->value;

// 	current->content = next->content;
// 	current->name = next->name;
// 	current->value = next->value;

// 	next->content = content_temp;
// 	next->name = name_temp;
// 	next->value = value_temp;
// }

// void	sort_var(t_var *lst)
// {
// 	t_var	*current;
// 	int		swap;

// 	// if (!lst)
// 	// 	return ;
// 	swap = 1;
// 	while (swap)
// 	{
// 		swap = 0;
// 		current = lst;
// 		while (current && current->next)
// 		{
// 			if (ft_strcmp(current->name, current->next->name) > 0)
// 			{
// 				swap_nodes(current, current->next);
// 				swap = 1;
// 			}
// 			else
// 				current = current->next;
// 		}
// 	}
// }

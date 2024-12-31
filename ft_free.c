#include "mini.h"

void	free_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}


void    free_lst(t_var *lst)
{
    t_var   *temp;

    while (lst)
    {
        temp = lst->next;
        free(lst->content);
        free(lst->name);
        free(lst->value);
        free(lst);
        lst = temp;
    }
}

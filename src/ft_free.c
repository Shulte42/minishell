#include "../inc/libs.h"

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

void	free_lst(t_var *lst)
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

void	ft_tokenclear(t_tokens *lst)
{
	t_tokens	*tokens;
	t_tokens	*next;

	tokens = lst;
	while (tokens != NULL)
	{
		next = tokens->next;
		free(tokens->content);
		free(tokens);
		tokens = next;
	}
}

void	clean_cmd_list(t_command *lst)
{
	t_command	*temp;
	int			i;

	while (lst)
	{
		temp = lst;
		lst = lst->next;
		if (temp->cmd)
			free(temp->cmd);
		if (temp->args)
		{
			i = 0;
			while (temp->args[i])
				free(temp->args[i++]);
			free(temp->args);
		}
		if (temp->infile)
			free(temp->infile);
		if (temp->outfile)
			free(temp->outfile);
		if (temp->heredoc_delim)
			free(temp->heredoc_delim);
		free(temp);
	}
}

// TODO: melhorar essa funcao
void	free_exit(t_shell *data)
{
	free_lst(data->envvar);
	free_lst(data->envvar_export);
	ft_tokenclear(data->tokens);
	clean_cmd_list(data->commands);
	if (data->input)
		free(data->input);
}

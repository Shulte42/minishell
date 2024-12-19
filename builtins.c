#include "mini.h"

void	mini_echo(char	**args, int fd)
{
	bool	flag_nl;
	int		i;

	flag_nl = false;
	i = 1;
	if (args[i] && ft_strncmp(args[i], "-n", sizeof(args[i])) == 0)
	{
		flag_nl = true;
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

void	mini_pwd(void)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
		perror(pwd);
	else
	{
		printf("%s\n", pwd);
		free(pwd);
	}
}

void	mini_cd(char **args, t_mini	*data)
{
	char	*pwd_temp;

	pwd_temp = getcwd(NULL, 0);
	if (!args[1] || (ft_strncmp(args[1], "--", 2) == 0))
		data->pwd = getenv("HOME");
	else if (ft_strncmp(args[1], "-", 2) == 0)
	{
		if (data->old_pwd == NULL)
		{
			printf("No OLDPWD\n");
			return ;
		}
		else
			data->pwd = ft_strjoin_free(data->old_pwd, "");
	}
	else
 		data->pwd = args[1];
	if (chdir(data->pwd) != 0)
	{
		perror(data->pwd);
		return ;
	}
	data->old_pwd = ft_strjoin_free(pwd_temp,  "");
}

void	mini_env(t_var *lst)
{
	t_var	*current;

	current  = lst;
	while (current)
	{
		printf("%s\n", current->content);
		current = current->next;
	}
}

void	mini_export(t_var *lst)
{
	t_var	*current;

	current = lst;
	while (current)
	{
		printf("declare -x %s=\"%s\"\n", current->name, current->value);
		current = current->next;
	}
}

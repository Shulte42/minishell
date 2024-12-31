#include "mini.h"

void	mini_echo(char	**args, int fd)
{
	bool	flag_nl;
	int		i;

	if (!args)
		return ;
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

void	mini_pwd(t_mini	*data)
{
	char	*pwd;
	t_var	*pwd_envvar;

	pwd_envvar = find_envvar(data->envvar, "PWD");
	if (pwd_envvar)
	{
		printf("%s\n", pwd_envvar->value);
		return ;
	}
	else if (!pwd_envvar)
	{
		pwd = getcwd(NULL, 0);
		if (pwd == NULL)
		{
			perror(pwd);
			return ;
		}
		printf("%s\n", pwd);
		free(pwd);
	}
}

void	mini_cd(char **args, t_mini	*data)
{
	char	*pwd_temp;

	if (!args)
		return ;
	pwd_temp = getcwd(NULL, 0);
	if (!args[1] || (ft_strncmp(args[1], "--", 2) == 0))
		data->pwd = getenv("HOME");
	else if (ft_strncmp(args[1], "-", 2) == 0)
	{
		if (data->old_pwd == NULL)
		{
			printf("minishell: cd: no OLDPWD\n");
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

	/* verificar se tem argumentos, se tiver, exibir messagem de erro */
	current  = lst;
	while (current)
	{
		printf("%s\n", current->content);
		current = current->next;
	}
}

#include "mini.h"

char    *create_envvar_content(char *name, char *value)
{
    char    *content;

    content = (char *)malloc(ft_strlen(name) + ft_strlen(value) + 2);
    if (!content)
        return (NULL);
    ft_strcpy(content, name);
    ft_strcpy(content + ft_strlen(name), "=");
    ft_strcpy(content + ft_strlen(name) + 1, value);
    return (content);
}

void    update_envvar(t_var *envvar, char *name, char *value)
{
    free(envvar->name);
    free(envvar->value);
    free(envvar->content);
    envvar->name = ft_strdup(name);
    envvar->value = ft_strdup(value);
    envvar->content = create_envvar_content(name, value);
}

void    add_new_envvar(t_var *lst, char *name, char *value, int flag)
{
    t_var   *envvar;
    t_var   *copy;

    envvar = ft_calloc(1, sizeof(t_var));
    if (!envvar)
        return ;
    envvar->content = create_envvar_content(name, value);
    if (!envvar->content)
    {
        free (envvar);
        return ;
    }
    if (flag)
    {
        envvar->env = true;
        envvar->exp = true;
    }
    envvar->name = ft_strdup(name);
    envvar->value = ft_strdup(value);
    add_var_back(&lst, envvar);
}

void    set_envvar(t_mini *data, char *name, char *value, int flag)
{
    t_var   *envvar;

    envvar = find_envvar(data->envvar, name);
    if (envvar)
    {
        update_envvar(envvar, name, value);
        envvar = find_envvar(data->envvar_export, name);
        update_envvar(envvar, name, value);
    }
    else
    {
        add_new_envvar(data->envvar, name, value, flag);
        add_new_envvar(data->envvar_export, name, value, flag);
    }
}

void    arg_with_equal(t_mini *data, char *arg)
{
    t_var   *var;
    char    *name;
    char    *value;

    name = ft_strdup_two(arg, '=');
    value = ft_strdup(ft_strchr(arg, '=') + 1);
    var = find_envvar(data->envvar, name);
    if (var)
    {
        set_envvar(data, name, value, 1);
        free(name);
        free(value);
        return ;
    }
    set_envvar(data, name, value, 0);
    free(name);
    free(value);
}

void    var_no_value(t_mini *data, char *arg)
{
    t_var   *var;

    var = find_envvar(data->envvar, arg);
    if (var)
        var->exp = true;
    else
        set_envvar(data, arg, "", 0);
}

void    analize_arg_export(char **args)
{
    int i;

    i = 0;
    while (args[i])
    {
        ; // TODO
    }
}

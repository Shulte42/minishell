#include "mini.h"

void    update_envvar(t_var *envvar, char *name, char *value)
{
    free(envvar->name);
    free(envvar->value);
    free(envvar->content);
    envvar->name = ft_strdup(name);
    envvar->value = ft_strdup(value);
    envvar->content = create_envvar_content(name, value);
}

t_var   *copy_var_node(t_var *envvar)
{
    t_var   *copy;

    copy = ft_calloc(1, sizeof(t_var));
    if (!copy)
        return (NULL);
    copy->content = ft_strdup(envvar->content);
    copy->name = ft_strdup(envvar->name);
    copy->value = ft_strdup(envvar->value);
    copy->env = envvar->env;
    copy->exp = envvar->exp;
    copy->next = envvar->next;
    copy->prev = envvar->prev;
    return (copy);
}

void    add_new_envvar(t_mini *data, char *name, char *value, int flag)
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
    add_var_back(&data->envvar, envvar);
    copy = copy_var_node(envvar);
    add_var_back(&data->envvar_export, copy);
    sort_var(data->envvar_export);
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
        add_new_envvar(data, name, value, flag);
}

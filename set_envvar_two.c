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

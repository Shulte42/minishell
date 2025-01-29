/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <bruda-si@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:30:04 by bruda-si          #+#    #+#             */
/*   Updated: 2024/10/08 11:57:50 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[FDNUM][BUFFER_SIZE];
	char		*new_line;
	int			i;

	new_line = NULL;
	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		while (buffer[fd][i])
			buffer[fd][i] = '\0';
		return (NULL);
	}
	while (buffer[fd][0] || read(fd, buffer[fd], BUFFER_SIZE) > 0)
	{
		if (read(fd, 0, 0) < 0)
		{
			free(new_line);
			return (NULL);
		}
		new_line = ft_strjoin(new_line, buffer[fd]);
		if (ft_nlhandle(buffer[fd]) == 1)
			break ;
	}
	return (new_line);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:53:03 by lwee              #+#    #+#             */
/*   Updated: 2022/06/22 20:43:17 by lwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*storage[FD_SIZE];
	char		*buffer;
	char		*tmp;
	ssize_t		r;
	int			i;

	if (fd < 0 || fd > FD_SIZE)
		return (NULL);
	buffer = malloc(sizeof *buffer * (BUFFER_SIZE + 1)); 
	if (buffer == NULL)
		return (NULL);
	r = 1;
	while (!ft_strchr(storage[fd], '\n') && r != 0)
	{
		r = read(fd, buffer, BUFFER_SIZE);
		if (r == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[r] = '\0';
		if (storage[fd] = NULL)
			storage[fd] = ft_strdup("");
		tmp = storage[fd];
		storage[fd] = strjoin(tmp, buffer);
		free(tmp);
	}
}

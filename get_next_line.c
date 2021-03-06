/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:53:03 by lwee              #+#    #+#             */
/*   Updated: 2022/07/18 11:04:25 by lwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	read_line(int fd, char **storage)
{
	char	*buffer;
	char	*tmp;
	int		r;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE) + 1);
	if (buffer == NULL)
		return ;
	r = 1;
	while (r > 0)
	{
		r = read(fd, buffer, BUFFER_SIZE);
		if (r == -1)
		{
			ft_free_str(storage);
			break ;
		}
		buffer[r] = '\0';
		tmp = ft_strdup(*storage);
		ft_free_str(storage);
		*storage = ft_strjoin(tmp, buffer);
		ft_free_str(&tmp);
		if (find_newline(buffer) >= 0)
			break ;
	}
	ft_free_str(&buffer);
}

char	*get_line(char **storage)
{
	char	*line;
	char	*tmp;
	int		len;
	int		pos_newline;

	len = ft_strlen(*storage);
	pos_newline = find_newline(*storage);
	if (pos_newline != -1)
	{
		line = ft_substr(*storage, 0, pos_newline + 1);
		tmp = ft_substr(*storage, pos_newline + 1, len - pos_newline);
		ft_free_str(storage);
		*storage = ft_strdup(tmp);
		ft_free_str(&tmp);
	}
	else
	{
		line = ft_strdup(*storage);
		ft_free_str(storage);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_line(fd, &storage);
	if (storage && *storage)
		line = get_line(&storage);
	if (!line || *line == '\0')
	{
		ft_free_str(&storage);
		ft_free_str(&line);
		return (NULL);
	}
	return (line);
}

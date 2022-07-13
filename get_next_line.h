/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:58:58 by lwee              #+#    #+#             */
/*   Updated: 2022/07/14 05:41:26 by lwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define FD_SIZE 1024
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE BUFSIZ
# endif

// GNL
int		find_newline(char *str);
void	read_line(int fd, char **storage);
char	*get_line(char **storage);
char	*get_next_line(int fd);

// UTILS
void	ft_free_str(char **str);
int		ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_substr(const char *s, int start, int len);

#endif

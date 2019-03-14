/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 03:17:39 by mchi              #+#    #+#             */
/*   Updated: 2019/03/03 13:26:31 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

void		duplicate_line(char **left_over, char **line)
{
	const char	*new_line_pos;

	new_line_pos = ft_strchr(*left_over, '\n');
	if (new_line_pos == NULL)
	{
		*line = ft_strdup(*left_over);
		(*left_over)[0] = '\0';
	}
	else
	{
		*line = ft_strnew(new_line_pos - *left_over + 1);
		ft_strncpy(*line, *left_over, new_line_pos - *left_over + 1);
		(*line)[new_line_pos - *left_over] = '\0';
		ft_strcpy(*left_over, new_line_pos + 1);
	}
}

int			get_next_line(const int fd, char **line)
{
	char		buffer[BUFF_SIZE + 1];
	static char	*left_over[9999] = { 0 };
	char		*temp;
	int			ret;

	if (read(fd, buffer, 0) == -1)
		return (-1);
	if (left_over[fd] == NULL)
		left_over[fd] = ft_strnew(1);
	while ((ret = read(fd, buffer, BUFF_SIZE)))
	{
		buffer[ret] = '\0';
		temp = left_over[fd];
		left_over[fd] = ft_strjoin(left_over[fd], buffer);
		free(temp);
		if (ft_strchr(left_over[fd], '\n') != NULL)
			break ;
	}
	if (ret == -1)
		return (-1);
	if (ret == 0 && left_over[fd][0] == '\0')
		return (0);
	duplicate_line(&left_over[fd], line);
	return (1);
}

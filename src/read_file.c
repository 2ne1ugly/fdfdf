/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 13:22:58 by mchi              #+#    #+#             */
/*   Updated: 2019/03/03 15:20:59 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "get_next_line.h"
#include <fcntl.h>

t_quad		assign_quad(t_uint a, t_uint b, t_uint c, t_uint d)
{
	t_quad	quad;

	quad.index[0] = a;
	quad.index[1] = b;
	quad.index[2] = c;
	quad.index[3] = d;
	return (quad);
}

void		enter_quad(t_app *app)
{
	int	i;
	int	j;
	int	k;
	int pos;

	app->quad_count = (app->x_dim - 1) * (app->y_dim - 1);
	app->quad_buffer = malloc(sizeof(t_vector) * app->quad_count);
	i = 0;
	k = 0;
	while (i < app->x_dim - 1)
	{
		j = -1;
		while (++j < app->y_dim - 1)
		{
			pos = i + j * app->x_dim;
			app->quad_buffer[k] =
				assign_quad(
					pos + 1,
					pos,
					pos + app->x_dim,
					pos + app->x_dim + 1);
			k++;
		}
		i++;
	}
}

void		clean_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int			count_dim(t_app *app, char *file)
{
	int		fd;
	char	*raw;
	char	**splited;
	int		i;

	if ((fd = open(file, O_RDONLY)) < 0)
		return (0);
	app->x_dim = 0;
	app->y_dim = 0;
	while (get_next_line(fd, &raw) == 1)
	{
		if (app->x_dim == 0)
		{
			splited = ft_strsplit(raw, ' ');
			i = -1;
			while (splited[++i] != NULL)
				app->x_dim++;
			clean_tab(splited);
		}
		free(raw);
		app->y_dim++;
	}
	close(fd);
	return (1);
}

int			read_file(t_app *app, char *file)
{
	char	*raw;
	char	**splited;
	int		i;
	int		j;
	int		fd;

	if (!count_dim(app, file))
		return (0);
	app->vertex_count = app->x_dim * app->y_dim;
	app->vertex_buffer = malloc(sizeof(t_vector) * app->vertex_count);
	app->eval_vertex_buffer = malloc(sizeof(t_vector) * app->vertex_count);
	if ((fd = open(file, O_RDONLY)) < 0)
		return (0);
	i = 0;
	while (get_next_line(fd, &raw))
	{
		splited = ft_strsplit(raw, ' ');
		j = -1;
		while (splited[++j] != NULL)
			enter_vector(app, i, j, ft_atoi(splited[j]));
		clean_tab(splited);
		i++;
	}
	close(fd);
	return (1);
}

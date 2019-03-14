/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 18:16:59 by mchi              #+#    #+#             */
/*   Updated: 2019/03/03 22:59:52 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		trasnform_vertex_buffer(t_app *app, t_matrix *mat)
{
	unsigned i;

	i = 0;
	while (i < app->vertex_count)
	{
		vector_transform(&app->eval_vertex_buffer[i],
			&app->vertex_buffer[i], mat);
		app->eval_vertex_buffer[i].w = app->vertex_buffer[i].z;
		i++;
	}
}

void		trasnform_eval_vertex_buffer(t_app *app, t_matrix *mat)
{
	unsigned i;

	i = 0;
	while (i < app->vertex_count)
	{
		vector_transform(&app->eval_vertex_buffer[i],
			&app->eval_vertex_buffer[i], mat);
		i++;
	}
}

void		draw_vertex_buffer(t_app *app)
{
	unsigned i;

	i = 0;
	while (i < app->quad_count)
	{
		draw_quad(app, app->quad_buffer[i]);
		i++;
	}
}

int			app_looper(void *param)
{
	t_app		*app;
	t_matrix	mat;

	app = (t_app *)param;
	if (app->rotate == 1)
	{
		app->cam.x += (app->prev_y - app->y) / 300.0;
		app->cam.y += (app->prev_x - app->x) / 300.0;
		app->prev_y = app->y;
		app->prev_x = app->x;
	}
	else if (app->zoom == 1)
	{
		app->zoom_factor *= (1 + (app->prev_x - app->x) / 600.0);
		app->prev_y = app->y;
		app->prev_x = app->x;
	}
	mat = matrix_mul(look_at(app->cam), screen_mapping(app));
	trasnform_vertex_buffer(app, &mat);
	ft_memset(app->img.data_addr, 0, app->width * app->height * app->img.bpp);
	draw_vertex_buffer(app);
	mlx_put_image_to_window(app->mlx_handle,
		app->wnd_handle, app->img.ptr, 0, 0);
	return (0);
}

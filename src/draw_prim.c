/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_prim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 20:18:26 by mchi              #+#    #+#             */
/*   Updated: 2019/03/03 23:13:27 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <math.h>
#include <stdlib.h>

double	find_increment(t_vector *i, double dx, double dy)
{
	double	step;

	if (fabs(dx) > fabs(dy))
		step = fabs(dx);
	else
		step = fabs(dy);
	i->x = dx / step;
	i->y = dy / step;
	return (step);
}

int		round_number(double x)
{
	int val;

	val = (int)x;
	x -= val;
	if (x >= 0.5)
		val++;
	return (val);
}

void	draw_line(t_app *app, t_vector *from, t_vector *to)
{
	t_vector	i;
	t_vector	curr;
	double 		step;

	step = find_increment(&i, to->x - from->x, to->y - from->y);
	curr.x = from->x;
	curr.y = from->y;
	curr.w = from->w;
	while (step >= 0)
	{
		img_pixel_put(app, curr.x, curr.y, MAGENTA);
		curr.x += i.x;
		curr.y += i.y;
		step--;
	}
}

void	draw_quad(t_app *app, t_quad quad)
{
	t_vector *vec[4];

	vec[0] = &app->eval_vertex_buffer[quad.index[0]];
	vec[1] = &app->eval_vertex_buffer[quad.index[1]];
	vec[2] = &app->eval_vertex_buffer[quad.index[2]];
	vec[3] = &app->eval_vertex_buffer[quad.index[3]];
	if ((vec[1]->y - vec[0]->y) * (vec[2]->x - vec[1]->x) -
		(vec[2]->y - vec[1]->y) * (vec[1]->x - vec[0]->x) >= 0)
	{
		draw_line(app, vec[0], vec[1]);
		draw_line(app, vec[1], vec[2]);
		draw_line(app, vec[2], vec[3]);
		draw_line(app, vec[3], vec[0]);
	}
}

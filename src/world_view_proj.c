/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_view_proj.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 21:44:02 by mchi              #+#    #+#             */
/*   Updated: 2019/03/03 18:20:29 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

t_vector	calc_position(t_cam cam)
{
	t_vector result;

	result.x = (-cam.dist) * cos(cam.x) * sin(cam.y);
	result.y = (-cam.dist) * sin(cam.x);
	result.z = (-cam.dist) * cos(cam.x) * cos(cam.y);
	result.w = 1;
	return (result);
}

t_matrix	look_at(t_cam cam)
{
	t_matrix	result;
	t_vector	eye;
	t_vector	x_axis;
	t_vector	y_axis;
	t_vector	z_axis;

	eye = calc_position(cam);
	z_axis = vector_normal(assign_vector(-eye.x, -eye.y, -eye.z, 0));
	x_axis = vector_normal(vector_cross(assign_vector(0, 1, 0, 0), z_axis));
	y_axis = vector_cross(z_axis, x_axis);
	assign_vector_to_matrix(&result, &x_axis, 0);
	assign_vector_to_matrix(&result, &y_axis, 1);
	assign_vector_to_matrix(&result, &z_axis, 2);
	result.val[3][0] = -vector_dot(&x_axis, &eye);
	result.val[3][1] = -vector_dot(&y_axis, &eye);
	result.val[3][2] = -vector_dot(&z_axis, &eye);
	result.val[0][3] = 0;
	result.val[1][3] = 0;
	result.val[2][3] = 0;
	result.val[3][3] = 1;
	return (result);
}

t_matrix	screen_mapping(t_app *app)
{
	t_matrix	result;

	result.val[0][0] = app->zoom_factor;
	result.val[0][1] = 0;
	result.val[0][2] = 0;
	result.val[0][3] = 0;
	result.val[1][0] = 0;
	result.val[1][1] = app->zoom_factor;
	result.val[1][2] = 0;
	result.val[1][3] = 0;
	result.val[2][0] = 0;
	result.val[2][1] = 0;
	result.val[2][2] = 1;
	result.val[2][3] = 0;
	result.val[3][0] = app->width / 2;
	result.val[3][1] = app->height / 2;
	result.val[3][2] = 0;
	result.val[3][3] = 1;
	return (result);
}

t_matrix	perspective(t_app *app)
{
	t_matrix	result;
	double		scale;
	double		r;
	double		t;

	scale = tan(90 * 0.5 * M_PI / 180) * 0.1;
	r = app->width / app->height * scale;
	t = scale;
	result.val[0][0] = 2 * 0.1 / (r * 2);
	result.val[0][1] = 0;
	result.val[0][2] = 0;
	result.val[0][3] = 0;
	result.val[1][0] = 0;
	result.val[1][1] = 2 * 0.1 / (t * 2);
	result.val[1][2] = 0;
	result.val[1][3] = 0;
	result.val[2][0] = 0;
	result.val[2][1] = 0;
	result.val[2][2] = -(1000.1) / (999.9);
	result.val[2][3] = -1;
	result.val[3][0] = 0;
	result.val[3][1] = 0;
	result.val[3][2] = -2 * 100 / (999.9);
	result.val[3][3] = 0;
	return (result);
}

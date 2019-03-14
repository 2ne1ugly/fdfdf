/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 12:10:07 by mchi              #+#    #+#             */
/*   Updated: 2019/03/04 10:30:38 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		enter_vector(t_app *app, int i, int j, double z)
{
	app->vertex_buffer[j + i * app->x_dim].x = 100 * (j - app->x_dim / 2.0);
	app->vertex_buffer[j + i * app->x_dim].z = 100 * (i - app->y_dim / 2.0);
	app->vertex_buffer[j + i * app->x_dim].y = -z * 20;
	app->vertex_buffer[j + i * app->x_dim].w = 1;
	app->min_z = MIN(app->min_z, z);
	app->max_z = MAX(app->max_z, z);
}

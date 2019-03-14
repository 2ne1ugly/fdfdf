/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 15:11:13 by mchi              #+#    #+#             */
/*   Updated: 2019/03/03 22:48:51 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "fdf.h"

int	main(int argc, char **argv)
{
	t_app	*app;

	if (argc < 2)
		return (0);
	if (!init_app(&app))
		return (0);
	app->min_z = 999999999;
	app->max_z = -999999999;
	if (!read_file(app, argv[1]))
		return (0);
	init_img(app);
	enter_quad(app);
	if (argc == 5)
	{
		app->min_color = hex_to_uint(argv[2]);
		app->max_color = hex_to_uint(argv[3]);
	}
	else
	{
		app->min_color = 0x0F0F0F;
		app->max_color = 0xFFFFFF;
	}
	mlx_loop(app->mlx_handle);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 16:33:01 by mchi              #+#    #+#             */
/*   Updated: 2019/03/03 22:49:02 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "fdf.h"

void		hook_functions(t_app *app)
{
	mlx_hook(app->wnd_handle, 2, 0, app_key_press, app);
	mlx_hook(app->wnd_handle, 3, 0, app_key_release, app);
	mlx_hook(app->wnd_handle, 4, 0, app_mouse_press, app);
	mlx_hook(app->wnd_handle, 5, 0, app_mouse_release, app);
	mlx_hook(app->wnd_handle, 6, 0, app_mouse_move, app);
	mlx_loop_hook(app->mlx_handle, app_looper, app);
}

void		init_img(t_app *app)
{
	app->img.ptr =
		mlx_new_image(app->mlx_handle, app->width, app->height);
	app->img.data_addr =
		mlx_get_data_addr(app->img.ptr, &app->img.bpp,
			&app->img.sl, &app->img.endian);
	app->img.bpp /= 8;
}

t_uint		hex_to_uint(char *str)
{
	t_uint val;

	val = 0;
	while (*str != 0)
	{
		val *= 16;
		if (*str > 9)
			val += *str - 'A' + 10;
		else
			val += *str - '0';
	}
	return (val);
}

int			init_app(t_app **app)
{
	*app = malloc(sizeof(t_app));
	if (*app == NULL)
		return (0);
	(*app)->mlx_handle = mlx_init();
	if ((*app)->mlx_handle == NULL)
		return (0);
	(*app)->width = 900;
	(*app)->height = 900;
	(*app)->wnd_handle =
		mlx_new_window((*app)->mlx_handle,
			(*app)->width, (*app)->height, "wfew");
	if ((*app)->wnd_handle == NULL)
		return (0);
	(*app)->cam.x = -0.615472907;
	(*app)->cam.y = PI / 4;
	(*app)->cam.dist = 1000;
	(*app)->rotate = 0;
	(*app)->zoom = 0;
	(*app)->zoom_factor = 1;
	hook_functions((*app));
	return (1);
}

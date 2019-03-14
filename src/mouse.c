/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 12:09:44 by mchi              #+#    #+#             */
/*   Updated: 2019/03/03 18:07:37 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	app_mouse_press(int button, int x, int y, void *param)
{
	t_app	*app;

	x = y;
	app = (t_app *)param;
	if (button == 1)
		app->rotate = 1;
	if (button == 2)
		app->zoom = 0;
	return (0);
}

int	app_mouse_release(int button, int x, int y, void *param)
{
	t_app	*app;

	x = y;
	app = (t_app *)param;
	if (button == 1)
		app->rotate = 0;
	if (button == 2)
		app->zoom = 0;
	return (0);
}

int	app_mouse_move(int x, int y, void *param)
{
	t_app	*app;

	app = (t_app *)param;
	app->x = x;
	app->y = y;
	if (app->rotate == 0 && app->zoom == 0)
	{
		app->prev_x = x;
		app->prev_y = y;
	}
	return (0);
}

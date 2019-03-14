/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 18:30:32 by mchi              #+#    #+#             */
/*   Updated: 2019/03/03 18:20:15 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "fdf.h"

int	app_key_press(int keycode, void *param)
{
	t_app	*app;

	app = (t_app *)param;
	if (keycode == 53)
		exit(0);
	if (keycode == 125)
		app->cam.x -= 0.05;
	if (keycode == 126)
		app->cam.x += 0.05;
	if (keycode == 123)
		app->cam.y -= 0.05;
	if (keycode == 124)
		app->cam.y += 0.05;
	if (keycode == 116)
		app->cam.dist += 5;
	if (keycode == 121)
		app->cam.dist -= 5;
	if (keycode == 6)
		app->zoom = 1;
	return (0);
}

int	app_key_release(int keycode, void *param)
{
	t_app	*app;

	app = (t_app *)param;
	if (keycode == 6)
		app->zoom = 0;
	return (0);
}

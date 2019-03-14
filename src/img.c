/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 15:08:47 by mchi              #+#    #+#             */
/*   Updated: 2019/03/03 23:11:57 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	img_pixel_put(t_app *app, int x, int y, int color)
{
	if (x < 0 || y < 0 || (t_uint)x >= app->width || (t_uint)y >= app->height)
		return ;
	*(int *)(app->img.data_addr + (x + y * app->width) * app->img.bpp) = color;
}

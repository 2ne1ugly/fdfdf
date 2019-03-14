/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 19:16:49 by mchi              #+#    #+#             */
/*   Updated: 2019/03/03 14:46:53 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

t_vector	assign_vector(double x, double y, double z, double w)
{
	t_vector	vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	vector.w = w;
	return (vector);
}

double		vector_dot(t_vector *lhs, t_vector *rhs)
{
	double	result;

	result = 0;
	result += lhs->x * rhs->x;
	result += lhs->y * rhs->y;
	result += lhs->z * rhs->z;
	result += lhs->w * rhs->w;
	return (result);
}

t_vector	vector_cross(t_vector lhs, t_vector rhs)
{
	t_vector	result;

	result.x = lhs.y * rhs.z - lhs.z * rhs.y;
	result.y = -lhs.x * rhs.z + lhs.z * rhs.x;
	result.z = lhs.x * rhs.y - lhs.y * rhs.x;
	result.w = 0;
	return (result);
}

double		vector_abs(t_vector vec)
{
	double		result;

	result = vec.x * vec.x;
	result += vec.y * vec.y;
	result += vec.z * vec.z;
	result += vec.w * vec.w;
	return (sqrt(result));
}

t_vector	vector_normal(t_vector vec)
{
	t_vector	result;
	double		absolute;

	absolute = vector_abs(vec);
	result.x = vec.x / absolute;
	result.y = vec.y / absolute;
	result.z = vec.z / absolute;
	result.w = vec.w / absolute;
	return (result);
}

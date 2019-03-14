/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 18:44:28 by mchi              #+#    #+#             */
/*   Updated: 2019/03/03 18:21:15 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

t_matrix	matrix_mul(t_matrix lhs, t_matrix rhs)
{
	t_matrix	result;
	int			i;
	int			j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			result.val[i][j] = lhs.val[i][0] * rhs.val[0][j]
				+ lhs.val[i][1] * rhs.val[1][j] + lhs.val[i][2] * rhs.val[2][j]
				+ lhs.val[i][3] * rhs.val[3][j];
			j++;
		}
		i++;
	}
	return (result);
}

void		matrix_identity(t_matrix *mat)
{
	mat->val[0][0] = 1;
	mat->val[0][1] = 0;
	mat->val[0][2] = 0;
	mat->val[0][3] = 0;
	mat->val[1][0] = 0;
	mat->val[1][1] = 1;
	mat->val[1][2] = 0;
	mat->val[1][3] = 0;
	mat->val[2][0] = 0;
	mat->val[2][1] = 0;
	mat->val[2][2] = 1;
	mat->val[2][3] = 0;
	mat->val[3][0] = 0;
	mat->val[3][1] = 0;
	mat->val[3][2] = 0;
	mat->val[3][3] = 1;
}

t_matrix	rotation_matrix(double x, double y, double z)
{
	t_matrix result;

	result.val[0][0] = cos(y) * cos(z);
	result.val[0][1] = cos(y) * sin(z);
	result.val[0][2] = -sin(y);
	result.val[0][3] = 0;
	result.val[1][0] = sin(x) * sin(y) * cos(z) - cos(x) * sin(z);
	result.val[1][1] = sin(x) * sin(y) * sin(z) + cos(x) * cos(z);
	result.val[1][2] = sin(x) * cos(y);
	result.val[1][3] = 0;
	result.val[2][0] = cos(x) * sin(y) * cos(z) + sin(x) * sin(z);
	result.val[2][1] = cos(x) * sin(y) * sin(z) - sin(x) * cos(z);
	result.val[2][2] = cos(x) * cos(y);
	result.val[2][3] = 0;
	result.val[3][0] = 0;
	result.val[3][1] = 0;
	result.val[3][2] = 0;
	result.val[3][3] = 1;
	return (result);
}

void		vector_transform(t_vector *ret, t_vector *vec, t_matrix *mat)
{
	t_vector	result;

	result.x = vec->x * mat->val[0][0] + vec->y * mat->val[1][0] +
		vec->z * mat->val[2][0] + vec->w * mat->val[3][0];
	result.y = vec->x * mat->val[0][1] + vec->y * mat->val[1][1] +
		vec->z * mat->val[2][1] + vec->w * mat->val[3][1];
	result.z = vec->x * mat->val[0][2] + vec->y * mat->val[1][2] +
		vec->z * mat->val[2][2] + vec->w * mat->val[3][2];
	result.w = vec->x * mat->val[0][3] + vec->y * mat->val[1][3] +
		vec->z * mat->val[2][3] + vec->w * mat->val[3][3];
	ret->x = result.x;
	ret->y = result.y;
	ret->z = result.z;
	ret->w = result.w;
}

void		assign_vector_to_matrix(t_matrix *mat, t_vector *vec, int x)
{
	(*mat).val[0][x] = vec->x;
	(*mat).val[1][x] = vec->y;
	(*mat).val[2][x] = vec->z;
	(*mat).val[3][x] = vec->w;
}

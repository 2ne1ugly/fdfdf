/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 07:37:52 by mchi              #+#    #+#             */
/*   Updated: 2019/02/18 12:24:58 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int value, size_t num)
{
	unsigned char *target;

	target = (unsigned char *)ptr;
	while (num > 0)
	{
		if (*target == (unsigned char)value)
		{
			return (target);
		}
		target++;
		num--;
	}
	return (NULL);
}

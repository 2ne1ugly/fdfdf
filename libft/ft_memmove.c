/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 07:25:03 by mchi              #+#    #+#             */
/*   Updated: 2019/02/12 17:22:28 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t num)
{
	unsigned char *target;

	if (destination < source)
	{
		target = (unsigned char *)destination;
		while (num-- > 0)
		{
			*target = *((unsigned char *)source);
			target++;
			source++;
		}
	}
	else
	{
		target = (unsigned char *)destination + num - 1;
		source += num - 1;
		while (num-- > 0)
		{
			*target = *((unsigned char *)source);
			target--;
			source--;
		}
	}
	return (destination);
}

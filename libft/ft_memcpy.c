/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 07:07:40 by mchi              #+#    #+#             */
/*   Updated: 2019/02/12 17:19:38 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t num)
{
	unsigned char *target;

	target = (unsigned char *)destination;
	while (num > 0)
	{
		*target = *((unsigned char *)source);
		target++;
		source++;
		num--;
	}
	return (destination);
}

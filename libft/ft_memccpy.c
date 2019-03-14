/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 07:14:17 by mchi              #+#    #+#             */
/*   Updated: 2019/02/11 17:33:57 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	while (n > 0)
	{
		*(unsigned char *)dest = *((unsigned char *)src);
		dest++;
		if ((*(unsigned char *)src) == (unsigned char)c)
		{
			return (dest);
		}
		src++;
		n--;
	}
	return (NULL);
}

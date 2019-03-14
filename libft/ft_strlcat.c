/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 08:08:28 by mchi              #+#    #+#             */
/*   Updated: 2019/02/12 18:52:50 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	total_length;

	total_length = ft_strlen(src);
	while (size > 0 && *dst != '\0')
	{
		size--;
		total_length++;
		dst++;
	}
	if (size == 0)
		return (total_length);
	while (size > 1)
	{
		*dst = *src;
		dst++;
		src++;
		size--;
	}
	*dst = '\0';
	return (total_length);
}

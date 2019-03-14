/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 09:04:05 by mchi              #+#    #+#             */
/*   Updated: 2019/02/19 12:33:49 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	size_t str2_length;

	str2_length = ft_strlen(str2);
	if (*str2 == '\0')
		return ((char *)str1);
	while (*str1 != '\0' && len >= str2_length)
	{
		if (ft_strncmp(str1, str2, str2_length) == 0)
		{
			return ((char *)str1);
		}
		str1++;
		len--;
	}
	return (NULL);
}

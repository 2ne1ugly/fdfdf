/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 08:32:44 by mchi              #+#    #+#             */
/*   Updated: 2019/02/18 08:55:20 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *str1, const char *str2)
{
	size_t str2_length;

	str2_length = ft_strlen(str2);
	while (*str1 != '\0')
	{
		if (ft_strncmp(str1, str2, str2_length) == 0)
		{
			return ((char *)str1);
		}
		str1++;
	}
	if (*str2 == '\0')
		return ((char *)str1);
	return (NULL);
}

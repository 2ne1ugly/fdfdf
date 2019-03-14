/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 08:17:18 by mchi              #+#    #+#             */
/*   Updated: 2019/02/18 08:52:23 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int character)
{
	char *last_occur;

	if (*str == (char)character)
	{
		last_occur = (char *)str;
	}
	else
	{
		last_occur = NULL;
	}
	while (*str != '\0')
	{
		str++;
		if (*str == (char)character)
		{
			last_occur = (char *)str;
		}
	}
	return (last_occur);
}

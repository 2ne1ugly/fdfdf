/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 07:49:44 by mchi              #+#    #+#             */
/*   Updated: 2019/02/11 20:39:17 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *destination, const char *source, size_t num)
{
	char *target;

	target = destination;
	while (num > 0)
	{
		*target = *source;
		target++;
		if (*source != '\0')
		{
			source++;
		}
		num--;
	}
	return (destination);
}

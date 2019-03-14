/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 06:09:51 by mchi              #+#    #+#             */
/*   Updated: 2019/02/11 19:11:05 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *destination, const char *source)
{
	char	*target;

	target = destination;
	while (*source != '\0')
	{
		*target = *source;
		target++;
		source++;
	}
	*target = *source;
	return (destination);
}

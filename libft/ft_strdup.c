/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 05:56:02 by mchi              #+#    #+#             */
/*   Updated: 2019/02/12 17:17:08 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str1)
{
	char *new_string;

	new_string = (char *)malloc(sizeof(char) * (ft_strlen(str1) + 1));
	if (new_string == NULL)
	{
		return (NULL);
	}
	ft_strcpy(new_string, str1);
	return (new_string);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 11:32:47 by mchi              #+#    #+#             */
/*   Updated: 2019/02/12 19:21:50 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new_string;
	size_t	length;
	char	*target;

	length = ft_strlen(s);
	new_string = malloc(sizeof(char) * (length + 1));
	if (new_string == NULL)
		return (NULL);
	target = new_string;
	while (*s != '\0')
	{
		*target = f(*s);
		target++;
		s++;
	}
	*target = '\0';
	return (new_string);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 11:51:16 by mchi              #+#    #+#             */
/*   Updated: 2019/02/12 19:36:05 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new_string;
	int		i;

	new_string = (char *)malloc(sizeof(char) * (len + 1));
	if (new_string == NULL)
		return (NULL);
	i = 0;
	while (s[start] != '\0' && len > 0)
	{
		new_string[i] = s[start];
		start++;
		len--;
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}

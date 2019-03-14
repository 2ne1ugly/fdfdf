/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 11:46:20 by mchi              #+#    #+#             */
/*   Updated: 2019/02/19 12:31:35 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrot(const char *str, size_t n)
{
	char	*temp;
	int		size;

	size = ft_strlen(str);
	n %= size;
	temp = malloc(sizeof(char) * (size + 1));
	temp[size] = '\0';
	ft_strncpy(temp + n, str, size - n);
	ft_strncpy(temp, str, n);
	return (temp);
}

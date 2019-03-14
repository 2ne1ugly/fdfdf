/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 11:00:31 by mchi              #+#    #+#             */
/*   Updated: 2019/02/11 20:58:42 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *new_block;

	new_block = malloc(size);
	if (new_block == NULL)
	{
		return (NULL);
	}
	ft_bzero(new_block, size);
	return (new_block);
}

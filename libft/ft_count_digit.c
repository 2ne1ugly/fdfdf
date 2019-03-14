/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 12:13:28 by mchi              #+#    #+#             */
/*   Updated: 2019/02/19 12:13:42 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_digit(int n)
{
	int		digit_count;

	digit_count = 0;
	if (n < 0)
	{
		digit_count++;
	}
	while (n != 0)
	{
		digit_count++;
		n /= 10;
	}
	if (digit_count == 0)
	{
		digit_count++;
	}
	return (digit_count);
}

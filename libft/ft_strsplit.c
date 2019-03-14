/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:11:28 by mchi              #+#    #+#             */
/*   Updated: 2019/02/19 12:34:08 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	alloc_list(const char *s, char c, char ***list)
{
	int		count;

	count = 0;
	while (*s != '\0')
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s != '\0')
		{
			count++;
			while (*s != c && *s != '\0')
				s++;
		}
	}
	*list = (char **)malloc(sizeof(char *) * (unsigned long)(count + 1));
	if (*list != NULL)
		(*list)[count] = NULL;
}

char		**ft_strsplit(char const *s, char c)
{
	char	**list;
	int		i;
	int		length;

	alloc_list(s, c, &list);
	if (list == NULL)
		return (NULL);
	i = 0;
	while (*s != '\0')
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s == '\0')
			break ;
		length = ft_word_length(s, c);
		list[i] = (char *)malloc(sizeof(char) * (unsigned long)(length + 1));
		if (list[i] == NULL)
			return (NULL);
		ft_strncpy(list[i], s, (unsigned long)length);
		list[i][length] = '\0';
		while (*s != c && *s != '\0')
			s++;
		i++;
	}
	return (list);
}

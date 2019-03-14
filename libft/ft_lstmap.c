/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 17:06:40 by mchi              #+#    #+#             */
/*   Updated: 2019/02/12 21:17:27 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *root;
	t_list *current_node;

	if (lst == NULL)
		return (NULL);
	root = f(lst);
	if (root == NULL)
		return (NULL);
	current_node = root;
	lst = lst->next;
	while (lst != NULL)
	{
		current_node->next = f(lst);
		if (!current_node->next)
			return (NULL);
		current_node = current_node->next;
		lst = lst->next;
	}
	return (root);
}

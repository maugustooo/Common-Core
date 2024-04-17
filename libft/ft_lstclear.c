/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:19:41 by maugusto          #+#    #+#             */
/*   Updated: 2024/04/17 12:47:14 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *node;
	
	if (!del)
		return;
	if (lst)
	{
		while (*lst)
		{
			node = (*lst) -> next;
			(*del)((*lst) -> content);
			free(*lst);
			*lst = node;
		}
	}
}

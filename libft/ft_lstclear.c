/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:19:41 by maugusto          #+#    #+#             */
/*   Updated: 2024/04/22 15:48:14 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*temp;

	if (!del || !lst)
		return ;
	current = *lst;
	while (current)
	{
		temp = current;
		current = current -> next;
		del(temp -> content);
		free(temp);
	}
	*lst = NULL;
}

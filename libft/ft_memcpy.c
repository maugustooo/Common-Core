/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:17:15 by gude-jes          #+#    #+#             */
/*   Updated: 2024/04/16 12:14:54 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (!n || (!d && !s))
		return (dest);
	while (n--)
		*d++ = *s++;
	return (dest);
}

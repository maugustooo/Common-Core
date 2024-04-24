/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:52:43 by maugusto          #+#    #+#             */
/*   Updated: 2024/04/19 15:12:39 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	size;

	size = ft_strlen(src);
	i = 0;
	if (!dst || !src)
		return (0);
	if (n == 0)
		return (size);
	while ((src[i]) && (i < (n - 1)))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (size);
}

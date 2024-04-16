/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:23:18 by gude-jes          #+#    #+#             */
/*   Updated: 2024/04/16 10:19:57 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcpy(char *dst, const char *src, int n)
{
	int	i;
	int	size;

	size = ft_strlen(src);
	i = 0;
	if (!dst || !src)
		return (0);
	if (n <= 0)
		return (size);
	while ((src[i]) && (i < n - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (size);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:18:26 by gude-jes          #+#    #+#             */
/*   Updated: 2024/04/19 15:12:25 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	sleng;
	size_t	final_len;

	if (!s)
		return (NULL);
	sleng = ft_strlen(s);
	final_len = 0;
	if (start < sleng)
		final_len = sleng - start;
	if (final_len > len)
		final_len = len;
	sub = (char *)malloc(sizeof(char) * (final_len + 1));
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, s + start, final_len + 1);
	return (sub);
}

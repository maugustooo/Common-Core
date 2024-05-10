/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:18:26 by gude-jes          #+#    #+#             */
/*   Updated: 2024/04/22 11:05:18 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	char	*src;
	size_t	final_len;

	if (!s)
		return (NULL);
	src = (char *)s + start;
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (ft_strlen(src) < len)
		final_len = ft_strlen(src) + 1;
	else
		final_len = len + 1;
	sub = malloc(sizeof(char) * final_len);
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, src, final_len);
	return (sub);
}

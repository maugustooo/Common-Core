/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:04:39 by maugusto          #+#    #+#             */
/*   Updated: 2024/05/27 15:20:25 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strndup(char *s1, int len)
{
	char	*dest;
	int		i;

	dest = (char *) malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_gnlstrjoing(char *s1, char *s2)
{
	char	*newstring;
	int		i;
	int		j;
	int		size;

	if (!s1)
	{
		s1 = malloc(sizeof(char));
		s1[0] = '\0';
	}
	size = ft_strlen(s1) + ft_strlen(s2);
	newstring = malloc(sizeof(char *) * (size + 1));
	if (!newstring)
		return (0);
	i = -1;
	j = 0;
	while ((i < size) && (s1[++i]))
		newstring[i] = s1[i];
	while ((i < size) && (s2[j]))
		newstring[i++] = s2[j++];
	newstring[i] = '\0';
	if (s1)
		free (s1);
	return (newstring);
}

size_t	ft_strlentoc(char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

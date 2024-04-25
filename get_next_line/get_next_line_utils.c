/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:04:39 by maugusto          #+#    #+#             */
/*   Updated: 2024/04/25 17:39:48 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char  *s1, char  *s2)
{
	int		sizetotal;
	char	*res;
	int		i;
	int		j;

	i = 0;
	sizetotal = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(sizeof(char) * (sizetotal + 1));
	if (!res || !s1 || !s2)
		return (NULL);
	while (s1[i] != 0)
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[sizetotal] = 0;
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char )c)
		s++;
	if (*s == (char )c || !c)
		return ((char *) s);
	return (NULL);
}

size_t	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
void	ft_bzero(void *str, size_t n)
{
	size_t			i;
	unsigned char	*s;

	s = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		s[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if ((nmemb > 2147483647 && size != 0) || (size > 2147483647 && nmemb != 0))
		return (0);
	ptr = (void *)malloc(nmemb * size);
	if (!ptr)
		return (NULL);
		
	ft_bzero (ptr, nmemb * size);
	return (ptr);
}
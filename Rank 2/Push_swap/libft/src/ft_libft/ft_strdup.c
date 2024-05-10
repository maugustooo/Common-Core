/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:02:10 by rerodrig          #+#    #+#             */
/*   Updated: 2024/05/06 11:57:45 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

// strdup is a standard library function in the C programming language that
//duplicates a string. It creates a new memory block and copies the contents
//of the original string to the new memory block. Its syntax is as follows:
// char *strdup(const char *s);
// The function takes a single argument:
// s - A pointer to the string to be duplicated.
// The function returns a pointer to the new duplicated string,
//or NULL if the memory allocation fails.

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*copy;

	len = ft_strlen(s) + 1;
	copy = malloc(len);
	if (copy == NULL)
		return (NULL);
	len = 0;
	while (s[len])
	{
		copy[len] = s[len];
		len++;
	}
	copy[len] = '\0';
	return (copy);
}

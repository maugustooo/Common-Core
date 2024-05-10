/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:02:05 by rerodrig          #+#    #+#             */
/*   Updated: 2024/05/06 11:57:45 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

// The strchr() function returns a pointer to the first occurrence of the
//character c in the string s.
//  The strchr() and strrchr() functions return a pointer to the matched
//character or NULL if the character is not found.
//The terminating null byte is considered part of the string,
//so that if c is specified as '\0', these functions return a
//pointer to the terminator.

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *)s;
	while (*ptr)
	{
		if (*ptr == (unsigned char)c)
			return (ptr);
		ptr++;
	}
	if (c == 0)
		return (ptr);
	return (NULL);
}

// int main()
// {
//     const char *str = "dteste";
//     int character = 100;

//     char *result = ft_strchr(str, character);
//     printf("Result: %p\n", result);

//     return 0;
// }

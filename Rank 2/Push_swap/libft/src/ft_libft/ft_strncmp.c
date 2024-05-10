/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:02:38 by rerodrig          #+#    #+#             */
/*   Updated: 2024/05/06 11:57:45 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

// The function takes three arguments:
// str1 - A pointer to the first string to be compared.
// str2 - A pointer to the second string to be compared.
// n - The maximum number of characters to be compared.
// The function returns an integer value indicating the result of the
//comparison:
// If the two strings are equal up to the first n characters, it returns 0.
// If the first differing character in str1 is less than the corresponding
//character in str2, it returns a negative value.
// If the first differing character in str1 is greater than the
//corresponding character in str2, it returns a positive value.
// Note that strncmp only compares the first n characters of the strings.
//If the strings are shorter than n

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	while (n && *ptr1 && *ptr1 == *ptr2)
	{
		++ptr1;
		++ptr2;
		--n;
	}
	if (n)
		return (*ptr1 - *ptr2);
	else
		return (0);
}

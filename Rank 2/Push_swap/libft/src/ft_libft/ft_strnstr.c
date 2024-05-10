/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:02:42 by rerodrig          #+#    #+#             */
/*   Updated: 2024/05/06 11:57:45 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	k;
	size_t	j;
	size_t	l;

	k = ft_strlen(little);
	if (k == 0)
		return ((char *)big);
	j = 0;
	while (j < len && big[j])
	{
		if (big[j] == little[0])
		{
			l = 1;
			while (l < k && j + l < len && big[j + l] == little[l])
				l++;
			if (l == k)
				return ((char *)&big[j]);
		}
		j++;
	}
	return (NULL);
}
// strnstr - locate a substring in a string
// The Fn strnstr function locates the first occurrence of the null-terminated
//string Fa little in the string Fa big , where not more than Fa len characters
// are searched. Characters that appear after a `\0' character are not searched.
// Since the Fn strnstr function is a Fx specific API, it should only be used
// when portability is not a concern.
// If Fa little is an empty string, Fa big is returned; if Fa little
// occurs nowhere in Fa big , NULL is returned; otherwise a pointer to
// the first character of the first occurrence of Fa little is returned.
// const char *largestring = "Foo Bar Baz";
// const char *smallstring = "Bar"; c
// har *ptr; ptr = strnstr(largestring, smallstring, 4);
// // strnstr is a function in the C programming language that searches for
// a substring within a given string, up to a specified number of characters.
// Its syntax is as follows:
// Copy code
// char *strnstr(const char *haystack, const char *needle, size_t n);
// The function takes three arguments:
// haystack - A pointer to the string to be searched.
// needle - A pointer to the substring to be found.
// n - The maximum number of characters to search within haystack.
// The function returns a pointer to the first occurrence of needle within
// haystack, or NULL if needle is not found.
// The strnstr function works by searching for the first occurrence of
// the substring needle within the first n characters of haystack.
// If the substring is found, a pointer to the beginning of the
// substring within haystack is returned. If the substring is not
// found within the first n characters of haystack, the function returns
// NULL.

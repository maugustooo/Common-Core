/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:02:23 by rerodrig          #+#    #+#             */
/*   Updated: 2024/05/06 11:57:45 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	k;
	size_t	dst_len;
	size_t	src_len;

	k = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size == 0)
	{
		return (src_len);
	}
	if (dst == NULL)
	{
		return (0);
	}
	if (dst_len >= size)
		return (size + ft_strlen(src));
	while (src[k] != '\0' && k < size - dst_len - 1)
	{
		dst[dst_len + k] = src[k];
		k++;
	}
	dst[dst_len + k] = '\0';
	return (dst_len + src_len);
}

// The strlcpy() and strlcat() functions copy and concatenate strings with the
//same input parameters and output result as snprintf(3). They are designed to
//be safer, more consistent, and less error prone replacements for the easily
//misused functions strncpy(3) and strncat(3).
// strlcpy() and strlcat() take the full size of the destination buffer and
//guarantee NUL-termination if there is room. Note that room for the NUL
//should be included in dstsize.
// strlcpy() copies up to dstsize - 1 characters from the string src to dst,
//NUL-terminating the result if dstsize is not 0.
// strlcat() appends string src to the end of dst. It will append at most
// dstsize - strlen(dst) - 1 characters. It will then NUL-terminate, unless
// dstsize is 0 or the original dst string was longer than dstsize
// (in practice this should not happen as it means that either dstsize
// is incorrect or that dst is not a proper string).
// If the src and dst strings overlap, the behavior is undefined
// Besides quibbles over the return type (size_t versus int) and signal handler
//safety (snprintf(3) is not entirely safe on some systems), the following
//two are equivalent:
// n = strlcpy(dst, src, len);
// n = snprintf(dst, len, "%s", src);
// Like snprintf(3), the strlcpy() and strlcat() functions return the total
//length of the string they tried to create. For strlcpy() that means
//the length of src. For strlcat() that means the initial length of dst
//plus the length of src.
// If the return value is >= dstsize, the output string has been truncated.
//It is the caller's responsibility to handle this.

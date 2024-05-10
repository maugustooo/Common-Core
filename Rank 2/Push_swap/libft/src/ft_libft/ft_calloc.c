/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:00:43 by rerodrig          #+#    #+#             */
/*   Updated: 2024/05/06 11:57:45 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

//    The calloc() function allocates memory for an array of nmemb
//        elements of size bytes each and returns a pointer to the
//        allocated memory.  The memory is set to zero.  If nmemb or size
//        is 0, then calloc() returns either NULL, or a unique pointer
//        value that can later be successfully passed to free().  If the
//        multiplication of nmemb and size would result in integer
//        overflow, then calloc() returns an error.  By contrast, an
//        integer overflow would not be detected in the following call to
//        malloc(), with the result that an incorrectly sized block of
//        memory would be allocated:

//            malloc(nmemb * size);
// The malloc() and calloc() functions return a pointer to the
//        allocated memory, which is suitably aligned for any built-in
//        type.  On error, these functions return NULL.  NULL may also be
//        returned by a successful call to malloc() with a size of zero, or
//        by a successful call to calloc() with nmemb or size equal to
//        zero.

//        The free() function returns no value.

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	p = malloc(nmemb * size);
	if (!p)
		return (NULL);
	ft_bzero(p, nmemb * size);
	return (p);
}

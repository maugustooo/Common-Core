/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:01:25 by rerodrig          #+#    #+#             */
/*   Updated: 2024/05/06 11:57:45 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

//  The memchr() function scans the initial n bytes of the memory
//        area pointed to by s for the first instance of c.  Both c and the
//        bytes of the memory area pointed to by s are interpreted as
//        unsigned char.
//    The memchr() and memrchr() functions return a pointer to the
//    matching byte or NULL if the character does not occur in the
//    given memory area.

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;
	unsigned char		uc;

	uc = c;
	p = s;
	while (n-- > 0)
	{
		if (*p == uc)
		{
			return ((void *)p);
		}
		p++;
	}
	return (NULL);
}

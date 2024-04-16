/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:17:18 by gude-jes          #+#    #+#             */
/*   Updated: 2024/04/16 10:13:05 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*s;
	char	*d;

	d = (char *)dest;
	s = (char *)src;
	if (s < d)
		while (n--)
			d[n] = s[n];
	else
		ft_memcpy(d, s, n);
	return (dest);
}
// int main ()
// {
// 	char	src[] = "lorem ipsum dolor sit amet";
// 	char	*dest;
// 	int		arg;
// 		if (dest != ft_memmove(dest, "consectetur", 5))
// 			write(1, "dest's adress was not returned\n", 31);
// 		write(1, dest, 22);
// 	printf("%s", (char *)ft_memmove("Marco", "marcoo", 6));
// }

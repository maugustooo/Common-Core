/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:55:37 by maugusto          #+#    #+#             */
/*   Updated: 2024/04/24 14:29:23 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_hex(unsigned int n)
{
	int	i;

	i = 0;
	if (i == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

static	char	*hex_to_str(unsigned int n, char *base)
{
	int		size;
	char	*hex;

	size = count_hex(n);
	hex = malloc(sizeof(char *) * size + 1);
	if (!hex)
		return (NULL);
	hex[size] = '\0';
	while (size > 0)
	{
		hex[size --] = base[n % 16];
		n /= 16;
	}
	return (hex);
}

int	ft_putpointer(void *nbr, char *base)
{
	int				len;
	char			*str;
	unsigned long	n;

	n = (unsigned long)nbr;
	str = hex_to_str(n, base);
	len = ft_putstr(str);
	return (len);
}

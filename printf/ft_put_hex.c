/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:27:43 by maugusto          #+#    #+#             */
/*   Updated: 2024/04/24 14:28:25 by maugusto         ###   ########.fr       */
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

int	ft_put_hex(unsigned int nbr, char *base)
{
	char			*str;
	unsigned int	len;

	str = hex_to_str(nbr, base);
	len = ft_putstr(str);
	return (len);
}

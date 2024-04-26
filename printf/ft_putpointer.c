/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:55:37 by maugusto          #+#    #+#             */
/*   Updated: 2024/04/26 12:37:27 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putptrhex(unsigned long nbr, const char c)
{
	char	*base;
	int		result;

	result = 0;
	if (c == 'x')
		base = "0123456789abcdef";
	else if (c == 'X')
		base = "0123456789ABCDEF";
	if (nbr >= 16)
	{
		result += putptrhex((nbr / 16), c);
		result += putptrhex((nbr % 16), c);
	}
	else
	{
		result += write(1, &base[nbr], 1);
	}
	return (result);
}

int	ft_putpointer(unsigned long nbr)
{
	int		result;

	result = 0;
	if (!nbr)
		return (write(1, "(null)", 6));
	result += putptrhex(nbr, 'x');
	return (result);
}

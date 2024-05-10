/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:27:43 by maugusto          #+#    #+#             */
/*   Updated: 2024/04/29 15:50:36 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	puthex(unsigned long nbr, char *base)
{
	int		result;

	result = 0;
	if (nbr >= 16)
	{
		result += puthex((nbr / 16), base);
		result += puthex((nbr % 16), base);
	}
	else
	{
		result += write(1, &base[nbr], 1);
	}
	return (result);
}

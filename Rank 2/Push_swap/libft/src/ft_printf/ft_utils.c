/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:03:48 by rerodrig          #+#    #+#             */
/*   Updated: 2024/05/06 17:17:02 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_isflag(int c)
{
	return (ft_istype(c) || ft_isdigit(c) || ft_isspec(c));
}

int	ft_istype(int c)
{
	if (ft_strchr(CONVERSIONS, c))
		return (1);
	return (0);
}

int	ft_isspec(int c)
{
	if (ft_strchr(SPECIFIERS, c))
		return (1);
	return (0);
}

int	ft_nbr_len(unsigned int n, int base)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		i ++;
		n = n / base;
	}
	return (i);
}

int	ft_putpadding(int width, int len, int zero)
{
	int	count;

	count = 0;
	while (width - len > 0)
	{
		if (zero)
			count += ft_putchar_fd('0', 1);
		else
			count += ft_putchar_fd(' ', 1);
		width--;
	}
	return (count);
}

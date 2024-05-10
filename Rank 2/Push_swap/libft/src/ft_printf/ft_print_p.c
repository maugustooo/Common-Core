/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:00:43 by rerodrig          #+#    #+#             */
/*   Updated: 2024/05/06 10:59:33 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	ft_nbr_len_16(unsigned long n, int base)
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

int	ft_print_adr( unsigned long nbr)
{
	int		i;
	int		count;
	char	*hex_digits;
	char	buffer[16];

	i = 0;
	count = 0;
	hex_digits = "0123456789abcdef";
	if (nbr == 0)
	{
		count += ft_putnstr_fd("(nil)", 1, 5);
		return (count);
	}
	while (nbr > 0)
	{
		buffer[i++] = hex_digits[nbr % 16];
		nbr /= 16;
	}
	count += ft_putnstr_fd("0x", 1, 2);
	while (i > 0)
		count += ft_putchar_fd(buffer[--i], 1);
	return (count);
}

int	ft_print_ptr(t_flags *flags, unsigned long n)
{
	int	count;
	int	n_len;

	count = 0;
	n_len = ft_nbr_len_16(n, 16);
	if (n == 0)
		flags->width -= ft_strlen("(nil)") - 1;
	else
		flags->width -= 2;
	if (flags->minus == 1)
		count += ft_print_adr(n);
	count += ft_putpadding(flags->width, n_len, flags->zero);
	if (flags->minus == 0)
		count += ft_print_adr(n);
	return (count);
}

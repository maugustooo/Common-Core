/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:55:04 by rerodrig          #+#    #+#             */
/*   Updated: 2024/05/06 10:59:28 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	ft_putpadding_sign(t_flags *flags, int width, int zero, int left)
{
	int	count;

	count = 0;
	if (left)
	{
		count += ft_print_sign(flags);
		count += ft_putpadding(width, 0, zero);
	}
	else
	{
		count += ft_putpadding(width, 0, zero);
		count += ft_print_sign(flags);
	}
	return (count);
}

static int	ft_rightpadded(t_flags *flags, int t_width, int num, int zero_pad)
{
	int	count;
	int	n_len;

	count = 0;
	n_len = ft_nbr_len((int)num, 10);
	if (!flags->zero)
	{
		count += ft_putpadding_sign(flags, t_width, 0, 0);
		count += ft_putpadding(flags->precision, n_len, 1);
	}
	else
	{
		if (flags->dot)
			count += ft_putpadding_sign(flags, t_width, 0, 0);
		else
			count += ft_putpadding_sign(flags, t_width, flags->zero, 1);
		count += ft_putpadding(flags->precision, n_len, 1);
	}
	count += printf_putnbr(num);
	count += ft_putpadding(zero_pad, flags->width + flags->isneg + n_len,
			flags->zero);
	return (count);
}

static int	ft_leftpadded(t_flags *flags, int t_width, int num, int n_len)
{
	int	count;

	count = 0;
	count += ft_putpadding_sign(flags, flags->precision - n_len, 1, 1);
	count += printf_putnbr(num);
	count += ft_putpadding(flags->width, t_width, 0);
	return (count);
}

int	ft_print_int(t_flags *flags, int n)
{
	int	count;
	int	n_len;
	int	total_width;
	int	zero_padding;

	count = 0;
	flags->isneg = (n < 0);
	n = ft_abs(n);
	n_len = ft_nbr_len((int)n, 10);
	if (flags->precision == 0 && n == 0 && flags->dot)
		return (ft_putpadding(flags->width, 0, 0));
	total_width = n_len;
	if (flags->precision > n_len)
		total_width = flags->precision;
	zero_padding = 0;
	if (flags->zero && flags->precision == 0)
		zero_padding = flags->width - total_width - flags->isneg;
	if (flags->minus)
		count += ft_leftpadded(flags, total_width, n, n_len);
	else
	{
		total_width = flags->width - total_width - flags->isneg - flags->plus;
		count += ft_rightpadded(flags, total_width, n, zero_padding);
	}
	return (count);
}

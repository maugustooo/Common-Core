/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:01:32 by rerodrig          #+#    #+#             */
/*   Updated: 2024/05/06 17:16:58 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	printf_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		write(1, "2147483648", 10);
		return (10);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		count++;
		n = -n;
	}
	if (n >= 10)
		count += printf_putnbr(n / 10);
	n = n % 10 + '0';
	write(1, &n, 1);
	return (count + 1);
}

int	ft_abs(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

int	ft_print_sign(t_flags *flags)
{
	int	count;

	count = 0;
	if (flags->isneg)
	{
		count += ft_putchar_fd('-', 1);
		flags->width--;
	}
	else if (flags->plus)
	{
		count += ft_putchar_fd('+', 1);
		flags->width--;
	}
	else if (flags->space)
	{
		count += ft_putchar_fd(' ', 1);
		flags->width--;
	}
	return (count);
}

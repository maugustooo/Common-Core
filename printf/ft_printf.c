/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 09:38:00 by maugusto          #+#    #+#             */
/*   Updated: 2024/04/24 14:41:24 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_arg(const char *format, int i, va_list ap)
{
	if (format[i + 1] == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (format[i + 1] == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (format[i + 1] == 'p')
		return (ft_putpointer(va_arg(ap, void *),
				"0123456789abcdef"));
	else if (format[i + 1] == 'd' || format[i + 1] == 'i')
		return (ft_printnbr(va_arg(ap, int)));
	else if (format[i + 1] == 'u')
		return (ft_printnbr_u(va_arg(ap, unsigned int)));
	else if (format[i + 1] == 'x' || format[i + 1] == 'X')
	{
		if (format[i + 1] == 'X')
			return (ft_put_hex(va_arg(ap, unsigned int), "0123456789ABCDEF"));
		else
			return (ft_put_hex(va_arg(ap, unsigned int), "0123456789abcdef"));
	}
	else if (format[i + 1] == '%')
		return (ft_putchar(format[i + 1]));
	else
		return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		result;

	i = 0;
	result = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%' && ft_strchr("cspdiuxX%", format[i + 1]))
		{
			result += ft_printf_arg(format, i, ap);
		}
		else
		{
			result += ft_putchar(format[i]);
		}
	}
	va_end (ap);
	return (result);
}

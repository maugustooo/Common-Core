/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:01:45 by rerodrig          #+#    #+#             */
/*   Updated: 2024/05/06 17:16:53 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_parse_flags(const char *format, va_list args, t_flags *flags)
{
	int	i;

	i = 0;
	while (ft_strchr(CONVERSIONS, format[i]) == NULL)
	{
		if (format[i] == '-')
			flags->minus = 1;
		else if (format[i] == '#')
			flags->hash = 1;
		else if (format[i] == ' ')
			flags->space = 1;
		else if (format[i] == '+')
			flags->plus = 1;
		else if (format[i] == '0' && flags->minus == 0 && flags->width == 0)
			flags->zero = 1;
		else if (format[i] == '.')
			i += ft_parse_precision(format + i, args, flags);
		else if (format[i] == '*')
			flags = ft_parse_asterix(args, flags);
		else if (ft_isdigit(format[i]))
			flags = ft_parse_width(format + i, flags);
		i++;
	}
	return (i);
}

int	ft_print_arg(const char *format, va_list args, t_flags *flags)
{
	int	count;

	count = 0;
	if (*format == '%')
		count += ft_print_char(flags, '%');
	else if (*format == 'c')
		count += ft_print_char(flags, va_arg(args, int));
	else if (*format == 's')
		count += ft_print_str(flags, va_arg(args, char *));
	else if (*format == 'd' || *format == 'i')
		count += ft_print_int(flags, va_arg(args, int));
	else if (*format == 'x' || *format == 'X')
		count += ft_print_hex(flags, va_arg(args, unsigned int));
	else if (*format == 'u')
		count += ft_print_unsigned(flags, va_arg(args, unsigned int));
	else if (*format == 'p')
		count += ft_print_ptr(flags, (unsigned long)va_arg(args, void *));
	else
		return (0);
	format++;
	return (count);
}

int	ft_parse(const char *format, va_list args)
{
	int		count;
	t_flags	flags;

	count = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1) != '\0')
		{
			format++;
			flags = ft_flags_init();
			format += ft_parse_flags(format, args, &flags);
			flags.specifier = *format;
			if (flags.specifier != 0)
				count += ft_print_arg(format, args, &flags);
		}
		else
			count += write(1, format, 1);
		format++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	if (!format || *format == '\0')
		return (0);
	count = 0;
	va_start(args, format);
	count = ft_parse(format, args);
	va_end(args);
	return (count);
}

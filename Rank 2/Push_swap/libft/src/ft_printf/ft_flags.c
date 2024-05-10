/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:29:00 by rerodrig          #+#    #+#             */
/*   Updated: 2024/05/06 11:54:58 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_flags	ft_flags_init(void)
{
	t_flags	flags;

	flags.specifier = 0;
	flags.minus = 0;
	flags.zero = 0;
	flags.width = 0;
	flags.dot = 0;
	flags.precision = 0;
	flags.star = 0;
	flags.hash = 0;
	flags.space = 0;
	flags.plus = 0;
	flags.isneg = 0;
	return (flags);
}

t_flags	*ft_parse_width(const char *format, t_flags *flags)
{
	if (flags->star == 1)
		flags->width = 0;
	flags->width = (flags->width * 10) + (*format - '0');
	return (flags);
}

t_flags	*ft_parse_asterix(va_list args, t_flags *flags)
{
	flags->star = 1;
	flags->width = va_arg(args, int);
	return (flags);
}

int	ft_parse_precision(const char *format, va_list args, t_flags *flags)
{
	int	i;

	i = 0;
	format++;
	flags->dot = 1;
	if (*format == '*')
	{
		flags->precision = va_arg(args, int);
		i++;
	}
	else
	{
		flags->precision = 0;
		while (ft_isdigit(*format))
		{
			flags->precision = (flags->precision * 10) + (*format - '0');
			format++;
			i++;
		}
	}
	return (i);
}

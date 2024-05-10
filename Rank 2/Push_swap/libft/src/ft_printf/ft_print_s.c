/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:05:20 by rerodrig          #+#    #+#             */
/*   Updated: 2024/05/06 10:59:36 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	ft_print_with_padding(t_flags *flags, char *str, int precision)
{
	int	count;

	count = 0;
	if (flags->minus)
	{
		count += ft_putnstr_fd(str, 1, precision);
		count += ft_putpadding(flags->width, precision, flags->zero);
	}
	else
	{
		count += ft_putpadding(flags->width, precision, flags->zero);
		count += ft_putnstr_fd(str, 1, precision);
	}
	return (count);
}

int	ft_print_str(t_flags *flags, char *str)
{
	int	count;
	int	precision;
	int	str_len;

	count = 0;
	if (str == NULL && flags->precision > 0 && flags->precision < 6)
		return (ft_putpadding(flags->width, 0, 0));
	if (str == NULL)
		str = "(null)";
	str_len = ft_strlen(str);
	if (flags->dot > 0 && flags->precision < str_len)
		precision = flags->precision;
	else
		precision = str_len;
	if (flags->width > precision)
		count += ft_print_with_padding(flags, str, precision);
	else
		count += ft_putnstr_fd(str, 1, precision);
	return (count);
}

// int	ft_print_s(const char *str)
// {
// 	int	len;

// 	if (str == NULL)
// 	{
// 		write(1, "(null)", 6);
// 		return (6);
// 	}
// 	len = 0;
// 	while (str[len])
// 		len++;
// 	write(1, str, len);
// 	return (len);
// }

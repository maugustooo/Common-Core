/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:59:41 by rerodrig          #+#    #+#             */
/*   Updated: 2024/05/06 10:59:47 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*ft_xtoa(unsigned int h)
{
	int		i;
	char	*str;

	i = ft_nbr_len(h, 16);
	str = malloc(sizeof(char) * (i + 1));
	str[i] = '\0';
	i--;
	while (i >= 0)
	{
		str[i] = "0123456789abcdef"[ft_abs(h % 16)];
		h = h / 16;
		i--;
	}
	return (str);
}

static int	ft_print_x_prefix(int is_upper)
{
	if (is_upper == 1)
		ft_putnstr_fd("0X", 1, 2);
	else
		ft_putnstr_fd("0x", 1, 2);
	return (2);
}

static int	check_uppercase(t_flags *flags, char *str)
{
	int	is_upper;

	is_upper = 0;
	if (flags->specifier == 'X')
	{
		is_upper = 1;
		ft_strtoupper(str);
	}
	return (is_upper);
}

static int	ft_print_with_pad(t_flags *flags, char *str, int n, int is_upper)
{
	int	count;

	count = 0;
	if (flags->zero == 0 && flags->hash == 1 && n != 0)
		count += ft_print_x_prefix(is_upper);
	if (flags->dot)
		count += ft_putpadding(flags->precision - 1, ft_strlen(str) - 1, 1);
	count += ft_putnstr_fd(str, 1, ft_strlen(str));
	return (count);
}

int	ft_print_hex(t_flags *flags, unsigned int n)
{
	int		count;
	int		is_upper;
	char	*str;

	count = 0;
	if (flags->precision == 0 && n == 0 && flags->dot)
		return (ft_putpadding(flags->width, 0, 0));
	str = ft_xtoa(n);
	is_upper = check_uppercase(flags, str);
	if (flags->hash == 1 && flags->zero == 1)
		count += ft_print_x_prefix(is_upper);
	if (flags->minus == 1)
		count += ft_print_with_pad(flags, str, n, is_upper);
	if (flags->dot && (size_t)flags->precision < ft_strlen(str))
		flags->precision = ft_strlen(str);
	if (flags->dot && flags->hash == 0)
		count += ft_putpadding(flags->width, flags->precision, 0);
	else
		count += ft_putpadding(flags->width, ft_strlen(str), flags->zero);
	if (flags->minus == 0)
		count += ft_print_with_pad(flags, str, n, is_upper);
	free(str);
	return (count);
}

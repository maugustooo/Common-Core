/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:56:23 by rerodrig          #+#    #+#             */
/*   Updated: 2024/05/06 10:59:43 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void	ft_fill_res(int size, int offset, unsigned int n, char *res)
{
	while (size > offset)
	{
		res[size - 1] = n % 10 + '0';
		n = n / 10;
		size--;
	}
}

static char	*ft_utoa(unsigned int n)
{
	int		offset;
	int		size;
	char	*res;

	offset = 0;
	size = ft_nbr_len(n, 10);
	res = (char *)malloc(sizeof(char) * size + 1);
	if (!res)
		return (0);
	if (n == 0)
		res[0] = 0;
	ft_fill_res(size, offset, n, res);
	res[size] = '\0';
	return (res);
}

static int	ft_print_with_padding(t_flags *flags, char *str)
{
	int	count;

	count = 0;
	if (flags->precision >= 0)
		count += ft_putpadding(flags->precision - 1, ft_strlen(str) - 1, 1);
	else
		count += ft_putpadding(flags->width, ft_strlen(str), flags->zero);
	count += ft_putnstr_fd(str, 1, ft_strlen(str));
	return (count);
}

int	ft_print_unsigned(t_flags *flags, long nbr)
{
	int		count;
	char	*str;

	count = 0;
	if (nbr == 0 && flags->precision == 0 && flags->dot)
		return (ft_putpadding(flags->width, 0, 0));
	str = ft_utoa(nbr);
	if (!str)
		return (0);
	if (flags->minus == 1)
		count += ft_print_with_padding(flags, str);
	if (flags->precision >= 0 && flags->precision < (int)ft_strlen(str))
		flags->precision = ft_strlen(str);
	if (flags->dot)
		count += ft_putpadding(flags->width, flags->precision, 0);
	else
		count += ft_putpadding(flags->width, ft_strlen(str), flags->zero);
	if (flags->minus == 0)
		count += ft_print_with_padding(flags, str);
	free(str);
	return (count);
}

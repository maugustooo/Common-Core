/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:49:35 by rerodrig          #+#    #+#             */
/*   Updated: 2024/05/06 10:59:16 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_print_char(t_flags *flags, char c)
{
	int	count;

	count = 0;
	if (flags->minus == 1)
	{
		count += ft_putchar_fd(c, 1);
		count += ft_putpadding(flags->width, 1, flags->zero);
	}
	else
	{
		count += ft_putpadding(flags->width, 1, flags->zero);
		count += ft_putchar_fd(c, 1);
	}
	return (count);
}

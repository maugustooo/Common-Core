/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:52:54 by rerodrig          #+#    #+#             */
/*   Updated: 2024/05/06 16:53:43 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "./libft.h"

# define CONVERSIONS "%cspdiuxX"
# define SPECIFIERS "-0.*#+ "

typedef struct s_flags
{
	char	specifier;

	int		minus;
	int		zero;
	int		width;
	int		dot;
	int		precision;
	int		star;
	int		hash;
	int		space;
	int		plus;
	int		isneg;

}	t_flags;

t_flags	ft_flags_init(void);
t_flags	*ft_parse_width(const char *format, t_flags *flags);
t_flags	*ft_parse_asterix(va_list args, t_flags *flags);
int		ft_parse_precision(const char *format, va_list args, t_flags *flags);

int		ft_istype(int c);
int		ft_isspec(int c);
int		ft_isflag(int c);

int		ft_putchar(char c);
int		ft_print_char(t_flags *flags, char c);
int		ft_print_str(t_flags *flags, char *str);
int		ft_print_hex(t_flags *flags, unsigned int n);
int		ft_print_int(t_flags *flags, int n);
int		ft_print_unsigned(t_flags *flags, long nbr);
int		ft_print_ptr(t_flags *flags, unsigned long nbr);

int		ft_putpadding(int width, int len, int zero);
int		ft_nbr_len(unsigned int n, int base);
int		ft_abs(int n);
int		printf_putnbr(int n);
int		ft_print_sign(t_flags *flags);

int		ft_printf(const char *format, ...);

#endif

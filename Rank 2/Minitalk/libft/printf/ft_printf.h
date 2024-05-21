/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:35:55 by maugusto          #+#    #+#             */
/*   Updated: 2024/05/17 14:17:42 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft.h"

int		ft_printf(const char *str, ...);
int		ft_putchar(char c);
int		puthex(unsigned long nbr, char *base);
int		ft_putstr(char *str);
int		ft_printnbr(int nbr);
int		ft_putpointer(unsigned long nbr);
int		ft_uitoa(unsigned int n);
char	*ft_itoa(int n);

#endif
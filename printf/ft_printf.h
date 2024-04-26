/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:35:55 by maugusto          #+#    #+#             */
/*   Updated: 2024/04/26 12:36:06 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
int		ft_putchar(char c);
int		ft_put_hex(unsigned int nbr, char *base);
int		ft_putstr(char *str);
int		ft_putstr(char *str);
int		ft_printnbr(int nbr);
int		ft_printnbr_u(unsigned int nbr);
int		ft_putpointer(unsigned long nbr);
size_t	ft_strlen(char const *str);
char	*ft_itoa(int n);

#endif
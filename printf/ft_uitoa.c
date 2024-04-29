/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:16:40 by gude-jes          #+#    #+#             */
/*   Updated: 2024/04/29 15:41:26 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	ft_size(unsigned int n)
{
	int	count;

	count = 0;
	while (n != 0)
	{
		count ++;
		n /= 10;
	}
	return (count);
}

int	ft_uitoa(unsigned int n)
{
	char	*str;
	int		result;
	size_t	len;

	result = 0;
	len = ft_size(n);
	if (n == 0)
		return(ft_putchar('0'));
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len--] = '\0';
	while (n != 0)
	{
		str[len--] = (n % 10) + 48;
		n = (n / 10);
	}
	result = ft_putstr(str);
	free(str);
	return (result);
}

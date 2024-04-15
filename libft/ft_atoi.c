/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:05:29 by gude-jes          #+#    #+#             */
/*   Updated: 2024/04/10 11:44:07 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char *str)
{
	int	number;
	int	i;
	int	negative;

	i = 0;
	negative = 1;
	number = 0;
	while ((str[i] <= 13 && str[i] >= 8) || (str[i] == 32))
		i++;
	if ((str[i] == 43) || (str[i] == 45))
	{
		if (str[i] == 45)
			negative *= -1;
		i++;
	}
	if ((str[i] == 43) || (str[i] == 45))
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = (number * 10) + (str[i] - 48);
		i++;
	}
	return (number * negative);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerodrig <rerodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:01:21 by rerodrig          #+#    #+#             */
/*   Updated: 2024/05/06 11:57:45 by rerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	ft_get_size(int n)
{
	int	size;

	size = 0;
	if (n <= 0)
		size++;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

static void	ft_fill_res(int size, int offset, int n, char *res)
{
	while (size > offset)
	{
		res[size - 1] = n % 10 + '0';
		n = n / 10;
		size--;
	}
}

// char	*ft_itoa(long n)
// {
// 	int		offset;
// 	int		size;
// 	char	*res;

// 	offset = 0;
// 	size = ft_get_size(n);
// 	res = (char *)malloc(sizeof(char) * size + 1);
// 	if (!res)
// 		return (NULL);
// 	if (n == 0)
// 		res[0] = '0';
// 	// if (n == -2147483648)
// 	// {
// 	// 	res[0] = '-';
// 	// 	res[1] = '2';
// 	// 	n = 147483648;
// 	// 	offset = 2;
// 	// }
// 	if (n < 0)
// 	{
// 		res[0] = '-';
// 		offset = 1;
// 		n = -n;
// 	}
// 	ft_fill_res(size, offset, n, res);
// 	res[size] = '\0';
// 	return (res);
// }
char	*ft_itoa(int n)
{
	int		offset;
	int		size;
	char	*res;

	offset = 0;
	size = ft_get_size(n);
	res = (char *)malloc(sizeof(char) * size + 1);
	if (!res)
		return (0);
	if (n == -2147483648)
	{
		res[0] = '-';
		res[1] = '2';
		n = 147483648;
		offset = 2;
	}
	if (n < 0)
	{
		res[0] = '-';
		offset = 1;
		n = -n;
	}
	ft_fill_res(size, offset, n, res);
	res[size] = '\0';
	return (res);
}

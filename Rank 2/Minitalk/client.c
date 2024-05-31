/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 09:41:42 by maugusto          #+#    #+#             */
/*   Updated: 2024/05/29 12:04:14 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

size_t	usleep_dynamic(size_t n)
{
	size_t	i;

	i = 0;
	if (n <= 10000)
		i = 10;
	else if (n <= 30000)
		i = 100;
	else if (n <= 60000)
		i = 300;
	else if (n <= 100000)
		i = 500;
	else if (n <= 1000000)
		i = 10000;
	return (i);
}

void	send_str(int pid, char *str)
{
	int		bit;
	size_t	i;
	size_t	usleep_i;

	usleep_i = 0;
	i = 0;
	while (i <= ft_strlen(str))
	{
		bit = 0;
		while (bit < 8)
		{
			if ((str[i] >> bit) & 1)
				kill (pid, SIGUSR1);
			else
				kill (pid, SIGUSR2);
			usleep_i = usleep_dynamic(i);
			usleep(usleep_i);
			bit++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*str;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		str = argv[2];
		send_str(pid, str);
	}
	else
	{
		ft_printf("you have to send the pid and the string\n");
		ft_printf("Example:\n./client 123(pid) 42(string)");
	}
}

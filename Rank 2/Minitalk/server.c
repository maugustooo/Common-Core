/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:47:53 by maugusto          #+#    #+#             */
/*   Updated: 2024/05/21 13:59:42 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	arte(void)
{
	printf("\t\t\t __  __    _   _   _  ____ _   _ ____ _____ ___  \n");
	printf("\t\t\t|  \\/  |  / \\ | | | |/ ___| | | / ___|_   _/ _ \\ \n");
	printf("\t\t\t| |\\/| | / _ \\| | | | |  _| | | \\___ \\ | || | | |\n");
	printf("\t\t\t| |  | |/ ___ \\ |_| | |_| | |_| |___) || || |_| |\n");
	printf("\t\t\t|_|  |_/_/   \\_\\___/_\\____|\\___/|____/_|_| \\___/ \n");
	printf("\t\t\t    / ___|| ____|  _ \\ \\   / / ____|  _ \\        \n");
	printf("\t\t\t    \\___ \\|  _| | |_) \\ \\ / /|  _| | |_) |       \n");
	printf("\t\t\t     ___) | |___|  _ < \\ V / | |___|  _ <        \n");
	printf("\t\t\t    |____/|_____|_| \\_\\ \\_/  |_____|_| \\_\\       \n");
}

void	read_bits_and_print(int signal)
{
	static int	signal_received = 0;
	static char	received_char = 0;
	static int	bit = 0;

	if (signal == SIGUSR1)
		received_char = received_char | (1 << bit);
	bit += 1;
	if (bit == 8)
	{
		signal_received = 1;
		bit = 0;
	}
	if (signal_received)
	{
		ft_printf("%c",received_char);
		received_char = 0;
		signal_received = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	arte();
	printf("\t\t\t\tMAUGUSTO Server iniciado\n");
	printf("PID: %d\n", pid);
	while (1)
	{
		signal(SIGUSR1, read_bits_and_print);
		signal(SIGUSR2, read_bits_and_print);
	}
	return (0);
}

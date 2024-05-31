/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:47:53 by maugusto          #+#    #+#             */
/*   Updated: 2024/05/31 10:11:12 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

static char	*str = NULL;

void	art(void)
{
	ft_printf("\t\t\t __  __    _   _   _  ____ _   _ ____ _____ ___  \n");
	ft_printf("\t\t\t|  \\/  |  / \\ | | | |/ ___| | | / ___|_   _/ _ \\ \n");
	ft_printf("\t\t\t| |\\/| | / _ \\| | | | |  _| | | \\___ \\ | || | | |\n");
	ft_printf("\t\t\t| |  | |/ ___ \\ |_| | |_| | |_| |___) || || |_| |\n");
	ft_printf("\t\t\t|_|  |_/_/   \\_\\___/_\\____|\\___/|____/_|_| \\___/ \n");
	ft_printf("\t\t\t    / ___|| ____|  _ \\ \\   / / ____|  _ \\        \n");
	ft_printf("\t\t\t    \\___ \\|  _| | |_) \\ \\ / /|  _| | |_) |       \n");
	ft_printf("\t\t\t     ___) | |___|  _ < \\ V / | |___|  _ <        \n");
	ft_printf("\t\t\t    |____/|_____|_| \\_\\ \\_/  |_____|_| \\_\\       \n");
}

char *ft_cjoin(char *str, char c)
{
    char *newstring;
    int i;
    int size;

    if (!str)
    {
        str = malloc(sizeof(char)); 
        if (!str)
            return (NULL);
        str[0] = '\0';
    }
    size = ft_strlen(str);
    newstring = (char *)malloc(sizeof(char) * (size + 2));
    if (!newstring)
        return (NULL);
    i = 0;
    while (str[i])
    {
        newstring[i] = str[i];
        i++;
    }
    newstring[i++] = c;
    newstring[i] = '\0';
    free(str);
    return (newstring);
}

void	read_bits_and_print(int signal)
{
	static int	received_char = 0;
	static int	bit = 0;

	if (signal == SIGUSR1)
		received_char = received_char | (1 << bit);
	bit += 1;
	if (bit == 8)
	{
		if (received_char == '\0')
		{
			ft_printf("%s", str);
			free(str);
			str = NULL;
		}
		else
			str = ft_cjoin(str, received_char);
		bit = 0;
		received_char = 0;
	}
} 
int	main(void)
{
	int	pid;

	pid = getpid();
	art();
	ft_printf("\t\t\t\t  MAUGUSTO Server Initialized\n");
	ft_printf("PID: %d\n", pid);
	while (1)
	{
		signal(SIGUSR1, read_bits_and_print);
		signal(SIGUSR2, read_bits_and_print);
		
	}
}
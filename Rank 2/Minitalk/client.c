#include "libft/libft.h"
#include <signal.h>

void send_str(int pid, char *str)
{
	int bit;
	size_t i;

	i = 0;
	while (i < ft_strlen(str))
	{
		bit = 0;
		while (bit < 8)
		{
			if((str[i] >> bit)& 1)
				kill(pid,SIGUSR1);
			else
				kill(pid,SIGUSR2);
			usleep(100);
			bit++;
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	int pid;
	char *str;
	
	if(argc == 3)
	{
		pid = ft_atoi(argv[1]);	
		str = argv[2];
		send_str(pid, str);
	}
	else
		ft_printf("you have to send the pid and the string\nExample:\n./client 123 42");
}
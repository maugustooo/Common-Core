/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 12:29:09 by maugusto          #+#    #+#             */
/*   Updated: 2024/05/29 17:41:23 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"
/* 
Tecla W: 119
Tecla A: 97
Tecla S: 115
Tecla D: 100
Tecla Escape (ESC): 27
*/ 

int controls(int key_code, t_idk *game)
{
	int i;
	int j;

	i = game->i;
	j = game->j;
	if(key_code == 119)
	{
		
		j --;
		if(game->map[j][i] == '0')
		{
			game->map[j][i] = 'P';
			game->map[j + 1][i] = '0';
			game->i = i;
			game->j = j;
			game->moves ++;
		}
		if(game->map[j][i] == 'C')
		{
			game->map[j][i] = 'P';
			game->map[j + 1][i] = '0';
			game->collectables--;
			game->i = i;
			game->j = j;
			game->moves ++;
		}
		if (game->map[j][i] == 'E')
		{
			if(game->collectables == 0)
			{
			ft_printf(" ____   _    ____      _    ____  _____ _   _ ____  \n"
				"|  _ \\ / \\  |  _ \\    / \\  | __ )| ____| \\ | / ___| \n"
				"| |_) / _ \\ | |_) |  / _ \\ |  _ \\|  _| |  \\| \\___ \\ \n"
				"|  __/ ___ \\|  _ <  / ___ \\| |_) | |___| |\\  |___) |\n"
				"|_|_/_/__ \\_\\_| \\_\\/_/   \\_\\____/|_____|_| \\_|____/ \n"
				"  |  \\/  |  / \\  |  _ \\ / _ \\|  \\/  | __ )  / \\     \n"
				"  | |\\/| | / _ \\ | |_) | | | | |\\/| |  _ \\ / _ \\    \n"
				"  | |  | |/ ___ \\|  _ <| |_| | |  | | |_) / ___ \\   \n"
				"  |_|  |_/_/   \\_\\_| \\_\\___/|_|  |_|____/_/   \\_\\  \n");
			}
			else
				return(0);
			exit_game(game);
		}
		ft_printf("moves: %d\n", game->moves);
	}
	else if(key_code == 115)
	{
		j ++;
		if(game->map[j][i] == '0')
		{
			game->map[j][i] = 'P';
			game->map[j - 1][i] = '0';
			game->i = i;
			game->j = j;
			game->moves ++;
		}
		if(game->map[j][i] == 'C')
		{
			game->map[j][i] = 'P';
			game->map[j - 1][i] = '0';
			game->collectables--;
			game->i = i;
			game->j = j;
			game->moves ++;
		}
		if (game->map[j][i] == 'E')
		{
			if(game->collectables != 0)
				return(0);
			printf("%d", game->collectables);
			ft_printf(" ____   _    ____      _    ____  _____ _   _ ____  \n"
				"|  _ \\ / \\  |  _ \\    / \\  | __ )| ____| \\ | / ___| \n"
				"| |_) / _ \\ | |_) |  / _ \\ |  _ \\|  _| |  \\| \\___ \\ \n"
				"|  __/ ___ \\|  _ <  / ___ \\| |_) | |___| |\\  |___) |\n"
				"|_|_/_/__ \\_\\_| \\_\\/_/   \\_\\____/|_____|_| \\_|____/ \n"
				"  |  \\/  |  / \\  |  _ \\ / _ \\|  \\/  | __ )  / \\     \n"
				"  | |\\/| | / _ \\ | |_) | | | | |\\/| |  _ \\ / _ \\    \n"
				"  | |  | |/ ___ \\|  _ <| |_| | |  | | |_) / ___ \\   \n"
				"  |_|  |_/_/   \\_\\_| \\_\\___/|_|  |_|____/_/   \\_\\  \n");

			exit_game(game);
		}
		ft_printf("moves: %d\n", game->moves);
	}
	else if(key_code == 100)
	{
		i ++;
		if(game->map[j][i] == '0')
		{
			game->map[j][i] = 'P';
			game->map[j][i - 1] = '0';
			game->i = i;
			game->j = j;
			game->moves ++;
		}
		if(game->map[j][i] == 'C')
		{
			game->map[j][i] = 'P';
			game->map[j][i - 1] = '0';
			game->collectables--;
			game->i = i;
			game->j = j;
			game->moves ++;
		}
		if (game->map[j][i] == 'E')
		{
			if(game->collectables != 0)
				return(0);
			printf("%d", game->collectables);
			ft_printf(" ____   _    ____      _    ____  _____ _   _ ____  \n"
				"|  _ \\ / \\  |  _ \\    / \\  | __ )| ____| \\ | / ___| \n"
				"| |_) / _ \\ | |_) |  / _ \\ |  _ \\|  _| |  \\| \\___ \\ \n"
				"|  __/ ___ \\|  _ <  / ___ \\| |_) | |___| |\\  |___) |\n"
				"|_|_/_/__ \\_\\_| \\_\\/_/   \\_\\____/|_____|_| \\_|____/ \n"
				"  |  \\/  |  / \\  |  _ \\ / _ \\|  \\/  | __ )  / \\     \n"
				"  | |\\/| | / _ \\ | |_) | | | | |\\/| |  _ \\ / _ \\    \n"
				"  | |  | |/ ___ \\|  _ <| |_| | |  | | |_) / ___ \\   \n"
				"  |_|  |_/_/   \\_\\_| \\_\\___/|_|  |_|____/_/   \\_\\  \n");

			exit_game(game);
		}
		ft_printf("moves: %d\n", game->moves);
	}
	else if(key_code == 97)
	{
		
		i --;
		if(game->map[j][i] == '0')
		{
			game->map[j][i] = 'P';
			game->map[j][i + 1] = '0';
			game->i = i;
			game->j = j;
			game->moves ++;
		}
		if(game->map[j][i] == 'C')
		{
			game->map[j][i] = 'P';
			game->map[j][i + 1] = '0';
			game->collectables--;
			game->i = i;
			game->j = j;
			game->moves ++;
		}
		if (game->map[j][i] == 'E')
		{
			if(game->collectables != 0)
				return(0);
			printf("%d", game->collectables);
			ft_printf(" ____   _    ____      _    ____  _____ _   _ ____  \n"
				"|  _ \\ / \\  |  _ \\    / \\  | __ )| ____| \\ | / ___| \n"
				"| |_) / _ \\ | |_) |  / _ \\ |  _ \\|  _| |  \\| \\___ \\ \n"
				"|  __/ ___ \\|  _ <  / ___ \\| |_) | |___| |\\  |___) |\n"
				"|_|_/_/__ \\_\\_| \\_\\/_/   \\_\\____/|_____|_| \\_|____/ \n"
				"  |  \\/  |  / \\  |  _ \\ / _ \\|  \\/  | __ )  / \\     \n"
				"  | |\\/| | / _ \\ | |_) | | | | |\\/| |  _ \\ / _ \\    \n"
				"  | |  | |/ ___ \\|  _ <| |_| | |  | | |_) / ___ \\   \n"
				"  |_|  |_/_/   \\_\\_| \\_\\___/|_|  |_|____/_/   \\_\\  \n");

			exit_game(game);
		}
		ft_printf("moves: %d\n", game->moves);
	}
	else if(key_code == 65307)
		exit_game(game);
	put_img_in_game(game);
	return (1);
}

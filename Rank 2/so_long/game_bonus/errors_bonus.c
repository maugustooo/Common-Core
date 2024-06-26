/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 09:51:35 by maugusto          #+#    #+#             */
/*   Updated: 2024/06/18 19:02:34 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	count_checker(t_idk *game, int height, int width)
{
	if (game->map[height][width] != '1' &&
		game->map[height][width] != '0' &&
		game->map[height][width] != 'C' &&
		game->map[height][width] != 'E' &&
		game->map[height][width] != 'P' &&
		game->map[height][width] != 'N' &&
		game->map[height][width] != '\n')
	{
		game->enemy = 1;
		ft_printf("Error\nHere!%c\nheight:%i	width: %i\n", game->map[height][width],height,width);
		exit_game(game);
	}
	if (game->map[height][width] == 'P')
		game->p_count++;
	if (game->map[height][width] == 'E')
		game->e_count++;
	if (game->map[height][width] == 'C')
		game->c_count++;	
}

static void	check_count_and_rectangular(t_idk *game)
{
	static int	height = 0;
	int	width;

	while (height < game->heightmap - 1)
	{
		width = 0;
		while (width <= game->widthmap)
		{
			count_checker(game, height, width);
			width++;
		}
		height++;
	}
	if (!(game->p_count == 1 && game->e_count == 1 && game->c_count >= 1))
	{
		game->enemy = 1;
		ft_printf("Error\nsomething wrong either player, exit or collectable issue");
		exit_game(game);
	}
}

int	check_errors(t_idk *game)
{
	static int	i = 0;
	static int	j = 0;

	i = game->widthmap;
	while (j < i)
	{
		if (!(game->map[0][j] == '1' && game->map[game->heightmap - 1][j] ==
				'1'))
			return (0);
		j++;
	}
	i = game->heightmap;
	j = 0;
	while (j < i)
	{
		
		if (!(game->map[j][0] == '1' && game->map[j][game->widthmap - 1] ==
				'1'))
			return (0);
		j++;
	}
	check_count_and_rectangular(game);
	if (!check_path(game))
		exit_game(game);
	return (1);
}

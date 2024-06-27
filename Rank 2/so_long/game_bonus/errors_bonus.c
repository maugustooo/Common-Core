/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:57:01 by maugusto          #+#    #+#             */
/*   Updated: 2024/06/27 13:58:34 by maugusto         ###   ########.fr       */
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
		ft_printf("Error\nHere! %c\nheight: %i\twidth: %i\n",
			game->map[height][width], height, width);
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
	int	height;
	int	width;

	height = 0;
	while (height < game->heightmap)
	{
		width = 0;
		while (width < game->widthmap)
		{
			count_checker(game, height, width);
			width++;
		}
		height++;
	}
	if (!(game->p_count == 1 && game->e_count == 1 && game->c_count >= 1))
	{
		game->enemy = 1;
		ft_printf("Error\n");
		ft_printf("wrong either with player, exit or collectable issue\n");
		exit_game(game);
	}
}

int	check_errors(t_idk *game)
{
	int	i;

	i = game->widthmap;
	while (i > 0)
	{
		if (!(game->map[0][game->widthmap - i] == '1'
			&& game->map[game->heightmap - 1][game->widthmap - i] == '1'))
			return (0);
		i--;
	}
	i = game->heightmap;
	while (i > 0)
	{
		if (!(game->map[game->heightmap - i][0] == '1'
			&& game->map[game->heightmap - i][game->widthmap - 1] == '1'))
			return (0);
		i--;
	}
	check_count_and_rectangular(game);
	if (!check_path(game))
		exit_game(game);
	return (1);
}

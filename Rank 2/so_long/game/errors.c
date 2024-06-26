/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 09:51:35 by maugusto          #+#    #+#             */
/*   Updated: 2024/06/18 19:20:26 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	count_checker(t_idk *game, int height, int width)
{
	if (game->map[height][width] != '1' &&
		game->map[height][width] != '0' &&
		game->map[height][width] != 'C' &&
		game->map[height][width] != 'E' &&
		game->map[height][width] != 'P' &&
		game->map[height][width] != '\n')
	{
		ft_printf("\nError Here!%c\n", game->map[height][width]);
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
		ft_printf("Error\nSomething is wrong!\n");
		ft_printf("either player, exit or collectable issue\n");
		exit_game(game);
	}
}

int	check_errors(t_idk *game)
{
	int	i;
	int	j;

	i = game->widthmap;
	j = 0;
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
	if (!check_path(game))
		exit_game(game);
	check_count_and_rectangular(game);
	return (1);
}

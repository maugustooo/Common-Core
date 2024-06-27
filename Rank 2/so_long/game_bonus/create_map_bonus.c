/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:59:39 by maugusto          #+#    #+#             */
/*   Updated: 2024/06/27 15:29:21 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	put_movement(t_idk *game)
{
	int	width;
	int	height;

	height = 0;
	if (game->finish == 0)
	{
		while (height < game->heightmap)
		{
			width = 0;
			while (game->map[height][width])
			{
				if (game->map[height][width] == '0')
					mlx_put_image_to_window(game->mlx,
						game->window, game->floor, width * 124, height * 124);
				put_player(game, height, width);
				width++;
			}
			height++;
		}
	}
}

static void	put_colectables(t_idk *game, int height, int width)
{
	if (game->map[height][width] == 'C' && game->cflag == 0)
	{
		mlx_put_image_to_window(game->mlx,
			game->window, game->colectable, width * 124, height * 124);
		game->collectables++;
		game->cflag++;
	}
	else if (game->map[height][width] == 'C' && game->cflag == 1)
	{
		mlx_put_image_to_window(game->mlx,
			game->window, game->colectable2, width * 124, height * 124);
		game->collectables++;
		game->cflag++;
	}
	else if (game->map[height][width] == 'C' && game->cflag == 2)
	{
		mlx_put_image_to_window(game->mlx,
			game->window, game->colectable3, width * 124, height * 124);
		game->collectables++;
		game->cflag = 0;
	}
}

static void	put_things(t_idk *game, int height, int width)
{
	if (game->map[height][width] == '0')
		mlx_put_image_to_window(game->mlx,
			game->window, game->floor, width * 124, height * 124);
	if (game->map[height][width] == '1' && ((height == 0
		|| height == game->heightmap - 1) || width == 0
		|| width == game->widthmap - 1))
		mlx_put_image_to_window(game->mlx,
			game->window, game->wall, width * 124, height * 124);
	if (game->map[height][width] == 'P')
		mlx_put_image_to_window(game->mlx,
			game->window, game->player1, width * 124, height * 124);
	put_colectables(game, height, width);
	if (game->map[height][width] == 'E')
		mlx_put_image_to_window(game->mlx,
			game->window, game->exit, width * 124, height * 124);
	if (game->map[0][3] == '1' && game->map[1][3] == '1')
		mlx_put_image_to_window(game->mlx,
			game->window, game->wallg, 3 * 124, 0 * 124);
	if (game->map[height][width] == 'N' && game->enflag % 3 == 0)
		mlx_put_image_to_window(game->mlx,
			game->window, game->enf, width * 124, height * 124);
	if (game->map[height][width] == 'N' && game->enflag % 3 == 1)
		mlx_put_image_to_window(game->mlx, game->window,
			game->enc, width * 124, height * 124);
}

void	put_img_in_game(t_idk *game)
{
	int	height;
	int	width;

	height = 0;
	game->collectables = 0;
	while (height < game->heightmap && game->finish == 0)
	{
		width = -1;
		while (game->map[height][++width])
		{
			put_things(game, height, width);
			if (game->map[height][width] == 'N' && game->enflag % 3 == 2)
				mlx_put_image_to_window(game->mlx, game->window,
					game->enb, width * 124, height * 124);
			if (game->map[height][width] == 'N')
				game->enflag++;
			if (game->map[height][width] == '1' && ((height > 0
				&& height < game->heightmap - 1) && width > 0
				&& width < game->widthmap - 1))
				put_machines(game, height, width);
		}
		height++;
	}
	game->total_collectable = game->collectables;
	load_frames(game);
}

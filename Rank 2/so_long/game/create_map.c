/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:47:58 by maugusto          #+#    #+#             */
/*   Updated: 2024/06/27 15:33:52 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	put_walkers(t_idk *game, int height, int width)
{
	if (game->map[height][width] == '1' && height == game->heightmap - 2
		&& width < 5)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->m3,
			width * 124, height * 124);
	}
}

void	put_imgs_to_variables(t_idk *game)
{
	int	i;
	int	j;

	game->floor = mlx_xpm_file_to_image(game->mlx, "textures/floor124.xpm", &i,
			&j);
	game->wall = mlx_xpm_file_to_image(game->mlx, "textures/wall124.xpm", &i,
			&j);
	game->guy_in_wall = mlx_xpm_file_to_image(game->mlx, "textures/wallg.xpm",
			&i, &j);
	game->m1 = mlx_xpm_file_to_image(game->mlx, "textures/m1.xpm", &i, &j);
	game->m2 = mlx_xpm_file_to_image(game->mlx, "textures/m2.xpm", &i, &j);
	game->m3 = mlx_xpm_file_to_image(game->mlx, "textures/m3.xpm", &i, &j);
	game->m4 = mlx_xpm_file_to_image(game->mlx, "textures/m4.xpm", &i, &j);
	game->player1 = mlx_xpm_file_to_image(game->mlx, "textures/P1.xpm", &i,
			&j);
	game->collectable = mlx_xpm_file_to_image(game->mlx, "textures/C1.xpm",
			&i, &j);
	game->exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", &i, &j);
}

static void	put_machines(t_idk *game, int height, int width)
{
	if (game->map[height][width] == '1' && game->mflag == 0)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->m1,
			width * 124, height * 124);
		game->mflag++;
		return ;
	}
	if (game->map[height][width] == '1' && game->mflag == 1 && (height != 1
		|| width != 9) && (height < game->heightmap - 2 || width >= 5))
	{
		mlx_put_image_to_window(game->mlx, game->window, game->m2,
			width * 124, height * 124);
		game->mflag++;
		return ;
	}
	if (game->map[height][width] == '1' && game->mflag == 2 && (height != 1
		|| width != 9) && (height < game->heightmap - 2 || width >= 5))
	{
		mlx_put_image_to_window(game->mlx, game->window, game->m4,
			width * 124, height * 124);
		game->mflag = 0;
		return ;
	}
	put_walkers(game, height, width);
}

static void	put_things(t_idk *game, int height, int width)
{
	if (game->map[height][width] == '1' && ((height == 0 || height
			== game->heightmap - 1) || width == 0
			|| width == game->widthmap - 1))
		mlx_put_image_to_window(game->mlx, game->window, game->wall,
			width * 124, height * 124);
	if (game->map[0][3] == '1' && game->map[1][3] == '1')
		mlx_put_image_to_window(game->mlx, game->window, game->guy_in_wall,
			3 * 124, 0 * 124);
	if (game->map[height][width] == '0')
		mlx_put_image_to_window(game->mlx, game->window, game->floor,
			width * 124, height * 124);
	if (game->map[height][width] == 'P')
		mlx_put_image_to_window(game->mlx, game->window, game->player1,
			width * 124, height * 124);
	if (game->map[height][width] == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->window, game->collectable,
			width * 124, height * 124);
		game->collectables++;
	}
	if (game->map[height][width] == 'E')
		mlx_put_image_to_window(game->mlx, game->window, game->exit,
			width * 124, height * 124);
}

void	put_img_in_game(t_idk *game)
{
	int	height;
	int	width;

	height = 0;
	game->collectables = 0;
	while (height < game->heightmap)
	{
		width = 0;
		while (game->map[height][width])
		{
			put_things(game, height, width);
			if (game->map[height][width] == '1' && ((height > 0 && height
						< game->heightmap - 1) && width > 0
					&& width < game->widthmap - 1))
				put_machines(game, height, width);
			if (game->map[height][width] == '1' && height == 1 && width == 9)
			{
				mlx_put_image_to_window(game->mlx, game->window, game->m1,
					width * 124, height * 124);
				game->mflag++;
			}
			width++;
		}
		height++;
	}
}

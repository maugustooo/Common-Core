/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:47:58 by maugusto          #+#    #+#             */
/*   Updated: 2024/06/13 11:49:01 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"
	

void put_movement(t_idk *game)
{
	int width; 
	int height;
	
	height = 0;
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

void	put_imgs_to_variables(t_idk *game)
{
	int	i;
	int	j;

	game->floor = mlx_xpm_file_to_image(game->mlx, "map/floor124.xpm", &i, &j);
	game->wall = mlx_xpm_file_to_image(game->mlx, "map/wall124.xpm", &i, &j);
	game->wallg = mlx_xpm_file_to_image(game->mlx, "map/wallg.xpm", &i, &j);
	game->m1 = mlx_xpm_file_to_image(game->mlx, "map/m1.xpm", &i, &j);
	game->m2 = mlx_xpm_file_to_image(game->mlx, "map/m2.xpm", &i, &j);
	game->m3 = mlx_xpm_file_to_image(game->mlx, "map/m3.xpm", &i, &j);
	game->m4 = mlx_xpm_file_to_image(game->mlx, "map/m4.xpm", &i, &j);
	game->m5 = mlx_xpm_file_to_image(game->mlx, "map/m5.xpm", &i, &j);
	game->m6 = mlx_xpm_file_to_image(game->mlx, "map/m6.xpm", &i, &j);
	game->player1 = mlx_xpm_file_to_image(game->mlx, "map/P1.xpm", &i, &j);
	game->player2 = mlx_xpm_file_to_image(game->mlx, "map/P2.xpm", &i, &j);
	game->player3 = mlx_xpm_file_to_image(game->mlx, "map/P3.xpm", &i, &j);
	game->colectable = mlx_xpm_file_to_image(game->mlx, "map/C1.xpm", &i, &j);
	game->colectable2 = mlx_xpm_file_to_image(game->mlx, "map/C2.xpm", &i, &j);
	game->colectable3 = mlx_xpm_file_to_image(game->mlx, "map/C3.xpm", &i, &j);
	game->exit = mlx_xpm_file_to_image(game->mlx, "map/exit.xpm", &i, &j);
	game->black = mlx_xpm_file_to_image(game->mlx, "map/black.xpm", &i, &j);
	game->enc = mlx_xpm_file_to_image(game->mlx, "map/enc.xpm", &i, &j);
	game->enb = mlx_xpm_file_to_image(game->mlx, "map/enb.xpm", &i, &j);
	game->enf = mlx_xpm_file_to_image(game->mlx, "map/enf.xpm", &i, &j);
	game->endwin = mlx_xpm_file_to_image(game->mlx, "map/congrats.xpm", &i, &j);
	game->enddead = mlx_xpm_file_to_image(game->mlx, "map/died.xpm", &i, &j);
}

static void put_colectables(t_idk *game, int height, int width)
{
	
	if (game->map[height][width] == 'C' && game->cflag == 0)
	{		
		mlx_put_image_to_window(game->mlx,
			game->window, game->colectable, width * 124, height * 124);
		game->collectables++;
		game->cflag ++;
	}
	else if(game->map[height][width] == 'C' && game->cflag == 1)
	{		
		mlx_put_image_to_window(game->mlx,
			game->window, game->colectable2, width * 124, height * 124);
		game->collectables++;
		game->cflag++;
	}
	else if(game->map[height][width] == 'C' && game->cflag == 2)
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
	if (game->map[height][width] == '1' && ((height == 0 || height 
	== game->heightmap - 1) || width == 0 || width == game->widthmap - 1))
		mlx_put_image_to_window(game->mlx,
			game->window, game->wall, width * 124, height * 124);
	if (game->map[height][width] == 'P')
		mlx_put_image_to_window(game->mlx,
			game->window, game->player1, width * 124, height * 124);
	put_colectables(game, height, width);
	if (game->map[height][width] == 'E')
		mlx_put_image_to_window(game->mlx,
			game->window, game->exit, width * 124, height * 124);
	if (game->map[0][9] == '1' && game->map[1][9] == '1')
		mlx_put_image_to_window(game->mlx,
			game->window, game->wallg, 9 * 124, 0 * 124);
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
	while (height < game->heightmap)
	{
		width = 0;
		while (game->map[height][width])
		{
			put_things(game, height, width);
			if (game->map[height][width] == 'N' && game->enflag % 3 == 2)
				mlx_put_image_to_window(game->mlx, game->window, 
					game->enb, width * 124, height * 124);
			if(game->map[height][width] == 'N')
				game->enflag++;
			if (game->map[height][width] == '1' && ((height > 0 && height 
				< game->heightmap - 1) && width > 0 && width < game->widthmap - 1))
					put_machines(game, height, width);
			width++;
		}
		height++;
	}
	game->total_collectable = game->collectables;
	load_frames(game);
}

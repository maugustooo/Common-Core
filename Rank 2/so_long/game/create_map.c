#include "../so_long.h"

void put_imgs_to_variables(t_idk *game)
{
	int i;
	int j;

	game->floor = mlx_xpm_file_to_image(game->mlx, "map/floor124.xpm",&i, &j);
	game->wall = mlx_xpm_file_to_image(game->mlx,"map/wall124.xpm",&i, &j);
	game->guy_in_wall = mlx_xpm_file_to_image(game->mlx,"map/guy_in_wall.xpm",&i, &j);
	game->machine1 = mlx_xpm_file_to_image(game->mlx,"map/machine1.xpm",&i, &j);
	game->machine2 = mlx_xpm_file_to_image(game->mlx,"map/machine2.xpm",&i, &j);
	game->machine3 = mlx_xpm_file_to_image(game->mlx,"map/machine3.xpm",&i, &j);
	game->machine4 = mlx_xpm_file_to_image(game->mlx,"map/machine4.xpm",&i, &j);
	game->player1 = mlx_xpm_file_to_image(game->mlx,"map/player1floor.xpm",&i, &j);
	game->collectable = mlx_xpm_file_to_image(game->mlx,"map/New-Project-_2_.xpm",&i, &j);
	game->exit = mlx_xpm_file_to_image(game->mlx,"map/exit.xpm",&i, &j);
}

void put_machines(t_idk *game )
{
	int i;

	i = 1;
	while(i < 7)
	{
		mlx_put_image_to_window(game->mlx,
					game->window, game->machine3, i * 124, 6 * 124);
		i++;
	}
	if(game->map[1][9] == '1')
			mlx_put_image_to_window(game->mlx,
				game->window, game->machine1, 9 * 124, 1 * 124);
	if(game->map[3][6] == '1')
			mlx_put_image_to_window(game->mlx,
				game->window, game->machine2, 6 * 124, 3 * 124);
	if(game->map[0][9] == '1')
			mlx_put_image_to_window(game->mlx,
				game->window,game->guy_in_wall, 9 * 124, 0 * 124);
	if(game->map[5][8] == '1')
			mlx_put_image_to_window(game->mlx,
				game->window,game->machine4, 8 * 124, 5 * 124);				
}

void put_things(t_idk *game, int height, int width)
{
	if(game->map[height][width] == '1')
		mlx_put_image_to_window(game->mlx,
			game->window, game->wall, width * 124, height * 124);
	if(game->map[height][width] == '0')
		mlx_put_image_to_window(game->mlx,
			game->window, game->floor, width * 124, height * 124);
	if(game->map[height][width] == 'P')
	{
		mlx_put_image_to_window(game->mlx,
			game->window, game->player1, width * 124, height * 124);
		game->i = width;
		game->j = height;
	}
	if(game->map[height][width] == 'C')
	{
		mlx_put_image_to_window(game->mlx,
			game->window, game->collectable, width * 124, height * 124);
		game->collectables ++;
	}
	if(game->map[height][width] == 'E')
			mlx_put_image_to_window(game->mlx,
			game->window, game->exit, width * 124, height * 124);
}

void put_img_in_game(t_idk *game)
{
	static int height;
	static int width;

	height = 0;
	game->collectables = 0;
	while (height < game->heightmap)
	{
		width = 0;
		while (game->map[height][width])
		{
			put_things(game, height, width);
			width ++;
		}
		height++;
	}
	put_machines(game);
}

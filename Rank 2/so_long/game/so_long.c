/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:56:28 by maugusto          #+#    #+#             */
/*   Updated: 2024/06/03 18:27:23 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void destroy_images(t_idk *game)
{
	if (game && game->mlx && game->floor)
   		mlx_destroy_image(game->mlx, game->floor);
	if (game->wall)
        mlx_destroy_image(game->mlx, game->wall);
	if (game->guy_in_wall)
        mlx_destroy_image(game->mlx, game->guy_in_wall);
	if (game->machine1)
        mlx_destroy_image(game->mlx, game->machine1);
	if (game->machine2)
        mlx_destroy_image(game->mlx, game->machine2);
	if (game->machine3)
        mlx_destroy_image(game->mlx, game->machine3);
	if (game->machine4)
        mlx_destroy_image(game->mlx, game->machine4);
	if (game->player1)
        mlx_destroy_image(game->mlx, game->player1);
	if (game->collectable)
        mlx_destroy_image(game->mlx, game->collectable);
	if (game->exit)
        mlx_destroy_image(game->mlx, game->exit);
}

int exit_game(t_idk *game)
{
	int	line;

	line = 0;
	if (game && game->mlx)
		destroy_images(game);
	if (game && game->mlx)
		mlx_destroy_window(game->mlx, game->window);
	if (game && game->mlx)
		mlx_destroy_display(game->mlx);
	free(game->mlx);
	while (line < game->heightmap)
		free(game->map[line++]);
	free(game->map);
	exit(0);
}

int main(int argc, char **argv)
{
	(void) argc;
	t_idk game;
	
	game.moves = 0;
	ft_memset(&game, 0, sizeof(t_idk));
	map_reading(&game, argv);
	if(!check_errors(&game))
	{
		ft_printf("Error\nThe map is wrong either Wall not corect or bad formated");
		exit_game(&game);
	}
	game.mlx = mlx_init();
    game.window = mlx_new_window(game.mlx, (game.widthmap * 124), (game.heightmap * 124), "So long");
	put_imgs_to_variables(&game);
	put_img_in_game(&game);
	mlx_key_hook(game.window, controls, &game);
	mlx_hook(game.window, 17, 0, (void *)exit, 0);
	mlx_loop(game.mlx);
}

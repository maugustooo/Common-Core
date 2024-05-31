/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:56:28 by maugusto          #+#    #+#             */
/*   Updated: 2024/05/29 17:33:29 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int exit_game(t_idk *game)
{
	int	line;

	line = 0;
	
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	free(game->mlx);
	while (line < game->heightmap - 1)
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
	game.mlx = mlx_init();
    game.window = mlx_new_window(game.mlx, (game.widthmap * 124), (game.heightmap * 124), "So long");
	put_imgs_to_variables(&game);
	put_img_in_game(&game);
	mlx_key_hook(game.window, controls, &game);
	mlx_hook(game.window, 17, 0, (void *)exit, 0);
	mlx_loop(game.mlx);
}

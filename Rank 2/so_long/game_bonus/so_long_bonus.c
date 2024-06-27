/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:42:59 by maugusto          #+#    #+#             */
/*   Updated: 2024/06/27 13:43:33 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_idk	game;

	if (argc != 2)
	{
		ft_printf("Just put the map\nExample:\n./so_long map.ber");
		return (0);
	}
	ft_memset(&game, 0, sizeof(t_idk));
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4)
		|| !map_reading(&game, argv[1]) || !check_errors(&game))
	{
		game.enemy = 1;
		ft_printf("Error\nThe map is bad formated\n");
		exit_game(&game);
	}
	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx, (game.widthmap * 124),
			((game.heightmap + 1) * 124), "So long");
	put_imgs_to_variables(&game);
	put_img_in_game(&game);
	mlx_key_hook(game.window, controls, &game);
	mlx_hook(game.window, 17, 0, (void *)exit, 0);
	mlx_loop_hook(game.mlx, render_next_frame, &game);
	mlx_loop(game.mlx);
}

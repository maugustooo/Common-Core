/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:56:28 by maugusto          #+#    #+#             */
/*   Updated: 2024/06/04 14:04:13 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	destroy_images(t_idk *game)
{
	if (game && game->mlx && game->floor)
		mlx_destroy_image(game->mlx, game->floor);
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->wallg)
		mlx_destroy_image(game->mlx, game->wallg);
	if (game->m1)
		mlx_destroy_image(game->mlx, game->m1);
	if (game->m2)
		mlx_destroy_image(game->mlx, game->m2);
	if (game->m3)
		mlx_destroy_image(game->mlx, game->m3);
	if (game->m4)
		mlx_destroy_image(game->mlx, game->m4);
	if (game->m5)
		mlx_destroy_image(game->mlx, game->m5);
	if (game->m6)
		mlx_destroy_image(game->mlx, game->m6);
	if (game->player1)
		mlx_destroy_image(game->mlx, game->player1);
	if (game->player2)
		mlx_destroy_image(game->mlx, game->player2);
	if (game->player3)
		mlx_destroy_image(game->mlx, game->player3);
}

void	destroy_imagesv2(t_idk *game)
{
	int line;
	
	line = 0;
	if (game->colectable)
		mlx_destroy_image(game->mlx, game->colectable);
	if (game->colectable2)
		mlx_destroy_image(game->mlx, game->colectable2);
	if (game->colectable3)
		mlx_destroy_image(game->mlx, game->colectable3);
	if (game->exit)
		mlx_destroy_image(game->mlx, game->exit);
	if (game->black)
		mlx_destroy_image(game->mlx, game->black);
	if (game->enc)
		mlx_destroy_image(game->mlx, game->enc);
	if (game->enb)
		mlx_destroy_image(game->mlx, game->enb);
	if (game->enf)
		mlx_destroy_image(game->mlx, game->enf);
	if (game->enddead)
		mlx_destroy_image(game->mlx, game->enddead);
	if (game->endwin)
		mlx_destroy_image(game->mlx, game->endwin);
	while (line < FRAMES) 
	{
    	if (game->gif[line] != NULL) 
		{
        	mlx_destroy_image(game->mlx, game->gif[line]);
        	game->gif[line] = NULL; // Importante para evitar uso após liberação
    	}
    line++;
	}
}

void limpar_recursos(t_idk *game)
{
    int line;
	
	line = 0;
	if (game && game->mlx)
	{
        destroy_images(game);
		destroy_imagesv2(game);
		while (line < FRAMES)
		{
			mlx_destroy_image(game->mlx, game->gif);
		}
	}
    if (game && game->mlx)
        mlx_destroy_window(game->mlx, game->window);
    if (game && game->mlx)
        mlx_destroy_display(game->mlx);
    free(game->mlx);
    while (line < game->heightmap)
        free(game->map[line++]);
    free(game->map);
}

int exit_game(t_idk *game)
{
	game->gifflag = 1;
	if(game->enemy != 1)
	{	
		if (game->enemy == 2)
			mlx_put_image_to_window(game->mlx, game->window, game->enddead,
			(game->widthmap / 2) - 6, (game->heightmap / 2) - 3);
		if (game->enemy == 0)
			mlx_put_image_to_window(game->mlx, game->window, game->endwin,
			(game->widthmap / 2) - 6, (game->heightmap / 2) - 3);
		signal(SIGALRM, exit);
		alarm(3);
		mlx_loop(game->mlx);
	}
	limpar_recursos(game);
    if(game->enemy == 1)
		exit(0);
	return(0);
}

int	main()
{
	t_idk	game;
	
	ft_memset(&game, 0, sizeof(t_idk));
	map_reading(&game);
	if (!check_errors(&game))
	{
		ft_printf("Error\nThe map is bad formated");
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

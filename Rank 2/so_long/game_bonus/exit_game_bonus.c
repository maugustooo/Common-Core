/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 11:30:36 by maugusto          #+#    #+#             */
/*   Updated: 2024/06/27 15:56:47 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	destroy_images(t_idk *game)
{
	if (game->floor)
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
}

void	clean_resources(t_idk *game)
{
	int	line;

	line = -1;
	if (game && game->mlx)
	{
		destroy_images(game);
		destroy_imagesv2(game);
		while (++line < FRAMES)
			if (game->gif[line])
				mlx_destroy_image(game->mlx, game->gif[line]);
		free(game->gif);
		line = 0;
		while (line < game->heightmap)
			free(game->map[line++]);
		free(game->map);
	}
	if (game && game->mlx)
		mlx_destroy_window(game->mlx, game->window);
	if (game && game->mlx)
		mlx_destroy_display(game->mlx);
	free(game->mlx);
}

int	wait_and_exit(void *param)
{
	t_idk	*game;

	game = (t_idk *)param;
	if (difftime(time(NULL), game->start_time) >= 3)
	{
		clean_resources(game);
		exit(0);
	}
	return (0);
}

int	exit_game(t_idk *game)
{
	game->finish = 1;
	if (game->enemy != 1)
	{
		if (game->enemy == DEAD)
			mlx_put_image_to_window(game->mlx, game->window,
				game->enddead, (game->widthmap / 2) - 6,
				(game->heightmap / 2) - 3);
		if (game->enemy == WIN)
			mlx_put_image_to_window(game->mlx, game->window,
				game->endwin, (game->widthmap / 2) - 6,
				(game->heightmap / 2) - 3);
		game->start_time = time(NULL);
		mlx_loop_hook(game->mlx, wait_and_exit, game);
		mlx_loop(game->mlx);
	}
	clean_resources(game);
	exit(0);
}

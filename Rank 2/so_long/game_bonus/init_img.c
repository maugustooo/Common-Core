/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:29:23 by maugusto          #+#    #+#             */
/*   Updated: 2024/06/27 16:20:31 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static int	put_imgs_to_variablesv3(t_idk *game)
{
	int	i;
	int	j;
	
	game->m1 = mlx_xpm_file_to_image(game->mlx, "textures/m1.xpm", &i, &j);
	game->m2 = mlx_xpm_file_to_image(game->mlx, "textures/m2.xpm", &i, &j);
	game->m3 = mlx_xpm_file_to_image(game->mlx, "textures/m3.xpm", &i, &j);
	game->m4 = mlx_xpm_file_to_image(game->mlx, "textures/m4.xpm", &i, &j);
	game->m5 = mlx_xpm_file_to_image(game->mlx, "textures/m5.xpm", &i, &j);
	game->m6 = mlx_xpm_file_to_image(game->mlx, "textures/m6.xpm", &i, &j);
	if(!game->m1 || !game->m2 || !game->m3 || !game->m4
		|| !game->m5 || !game->m6)
		return(0);
}
static int	put_imgs_to_variablesv2(t_idk *game)
{
	int	i;
	int	j;
	
	game->player1 = mlx_xpm_file_to_image(game->mlx, "textures/P1.xpm", &i,
			&j);
	game->player2 = mlx_xpm_file_to_image(game->mlx, "textures/P2.xpm", &i,
			&j);
	game->player3 = mlx_xpm_file_to_image(game->mlx, "textures/P3.xpm", &i,
			&j);
	game->colectable = mlx_xpm_file_to_image(game->mlx, "textures/C1.xpm", &i,
			&j);
	game->colectable2 = mlx_xpm_file_to_image(game->mlx, "textures/C2.xpm", &i,
			&j);
	game->colectable3 = mlx_xpm_file_to_image(game->mlx, "textures/C3.xpm", &i,
			&j);
	game->exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", &i,
			&j);
	if(!game->player1 || !game->player2 || !game->player3 || !game->colectable 
		|| !game->colectable2 || !game->colectable3 || !game->exit
		|| !put_imgs_to_variablesv3(game))
		return(0);
	;
	return(1);
}

int	put_imgs_to_variables(t_idk *game)
{
	int	i;
	int	j;

	game->floor = mlx_xpm_file_to_image(game->mlx, "textures/floor124.xpm", &i,
			&j);
	game->wall = mlx_xpm_file_to_image(game->mlx, "textures/wall124.xpm", &i,
			&j);
	game->wallg = mlx_xpm_file_to_image(game->mlx, "textures/wallg.xpm", &i,
			&j);
	game->black = mlx_xpm_file_to_image(game->mlx, "textures/black.xpm", &i,
			&j);
	game->enc = mlx_xpm_file_to_image(game->mlx, "textures/enc.xpm", &i, &j);
	game->enb = mlx_xpm_file_to_image(game->mlx, "textures/enb.xpm", &i, &j);
	game->enf = mlx_xpm_file_to_image(game->mlx, "textures/enf.xpm", &i, &j);
	game->endwin = mlx_xpm_file_to_image(game->mlx, "textures/congrats.xpm",
			&i, &j);
	game->enddead = mlx_xpm_file_to_image(game->mlx, "textures/died.xpm", &i,
			&j);
	if(!game->floor || !game->wall || !game->wallg || !game->black 
		|| !game->enc || !game->enb || !game->enf || game->endwin
		|| !game->enddead || !put_imgs_to_variablesv2(game))
		return(0);
	return(1);
}

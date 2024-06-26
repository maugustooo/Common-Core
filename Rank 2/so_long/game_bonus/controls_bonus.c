/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 12:29:09 by maugusto          #+#    #+#             */
/*   Updated: 2024/06/25 11:40:23 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"


static void put_moves(t_idk *game)
{
	char *movestr;
	char *movestr_number;
	char *movestr_final;
	
	movestr_final = NULL;
	movestr_number = ft_itoa(game->moves);
	movestr = "MOVES: ";
	movestr_final = ft_strjoin(movestr, movestr_number);
	free(movestr_number);
    mlx_put_image_to_window(game->mlx,game->window,
		game->black, (game->widthmap / 2) * 124, (game->heightmap) * 124);	
	mlx_string_put(game->mlx, game->window, (game->widthmap / 2) * 120,
		(game->heightmap + 1) * 115, 0xCF9D3B, movestr_final);
	free(movestr_final);
}
	
static int	moves(t_idk *game, int j, int i)
{
	if (game->map[j][i] == '0' || game->map[j][i] == 'N')
		game->map[j][i] = 'P';
	if (game->map[j][i] == 'C')
	{
		game->map[j][i] = 'P';
		game->collectables--;
	}
	if (game->map[j][i] == 'E')
	{
		if (game->collectables != 0)
			return (0);
		exit_game(game);
	}
	if (game->map[j][i] == '1')
		return (0);
	game->i = i;
	game->j = j;
	game->moves++;
	put_moves(game);
	return (1);
}

static int	move_left_right(int key_code, t_idk *game, int j, int i)
{
	int	moved;

	moved = 0;
	if (key_code == 'a')
	{	
		game->map[j][i] = '0';
		i--;
	}
	else if (key_code == 'd')
	{	
		game->map[j][i] = '0';
		i++;
	}
	if (game->map[j][i] == 'N')
			game->enemy = DEAD;
	moved = moves(game, j, i);
	if (!moved)
		return (0);
	return (1);
}

static int	move_up_down(int key_code, t_idk *game, int j, int i)
{
	int	moved;

	moved = 0;
	if (key_code == 'w')
	{	
		game->map[j][i] = '0';
		j--;
	}
	else if (key_code == 's')
	{	
		game->map[j][i] = '0';
		j++;
	}
	if (game->map[j][i] == 'N')
			game->enemy = DEAD;
	moved = moves(game, j, i);
	if (!moved)
		return (0);
	return (1);
}

int	controls(int key_code, t_idk *game)
{
	int	i;
	int	j;
	int	moved;
	
	i = game->i;
	j = game->j;
	if (key_code == 65307)
	{
		game->enemy = 1;
		exit_game(game);
	}
	if (key_code == 'w' || key_code == 's')
		moved = move_up_down(key_code, game, j, i);
	if (key_code == 'a' || key_code == 'd')
		moved = move_left_right(key_code, game, j, i);
	if (moved)
		put_movement(game);
	if(game->enemy == DEAD)
		exit_game(game);
	return (1);
}

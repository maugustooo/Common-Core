/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 12:29:09 by maugusto          #+#    #+#             */
/*   Updated: 2024/06/04 09:32:05 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"
/* 
Tecla W: 119
Tecla A: 97
Tecla S: 115
Tecla D: 100
Tecla Escape (ESC): 27
*/ 

static int moves( t_idk *game, int j, int i)
{
	if(game->map[j][i] == '0')
	{
		game->map[j][i] = 'P';
		game->i = i;
		game->j = j;
		game->moves ++;
	}
	if(game->map[j][i] == 'C')
	{
		game->map[j][i] = 'P';
		game->collectables--;
		game->i = i;
		game->j = j;
		game->moves ++;	
	}
	if (game->map[j][i] == 'E')
	{
		if(game->collectables != 0)
			return(0);
		exit_game(game);
	}
	if(game->map[j][i] == '1')
			return(0);
	return(1);
}

static int move_left_right(int key_code, t_idk *game, int j, int i)
{
	int moved;

	moved = 0;
	if(key_code == 97)
	{
		i --;
		moved = moves(game, j, i);
		if(!moved)
			return(0);
		game->map[j][i + 1] = '0';
	}
	else if(key_code == 100)
	{
		i ++;
		moved = moves(game, j, i);
		if(!moved)
			return(0);
		game->map[j][i - 1] = '0';
	}
	ft_printf("moves: %d\n", game->moves);
	return(1);
}

static int move_up_down(int key_code, t_idk *game, int j, int i)
{
	int moved;

	moved = 0;
	if(key_code == 119)
	{
		j --;
		moved = moves(game, j, i);
		if(!moved)
			return(0);
		game->map[j + 1][i] = '0';
	}
	else if(key_code == 115)
	{
		j ++;
		moved = moves(game, j, i);
		if(!moved)
			return(0);
		game->map[j - 1][i] = '0';
	}
	ft_printf("moves: %d\n", game->moves);
	return(1);
}

int controls(int key_code, t_idk *game)
{
	int i;
	int j;
	int moved;

	moved = 0;
	i = game->i;
	j = game->j;
	if(key_code == 65307)
		exit_game(game);
	if(key_code == 'w' || key_code == 's')
		moved = move_up_down(key_code, game, j, i);
	if(key_code == 'a' || key_code == 'd')
		moved = move_left_right(key_code, game, j, i);
	if(moved)
		put_img_in_game(game);
	return (1);
}

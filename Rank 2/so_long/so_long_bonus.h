/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 20:15:54 by prossi            #+#    #+#             */
/*   Updated: 2024/06/26 16:45:44 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
#include <pthread.h>
#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"
#include "libft/libft.h"

#define FRAMES 18
#define DEAD 2
#define WIN 0
#define RIGHT 65361
#define LEFT 65363
/// @brief data from game
/// @param flag flag to put each machine
/// @param cflag flag to put each collectable
/// @param enflag flag to put each enemy
/// @param enemy flag to see if the p touch an enemy
/// @param finish flag to check if the game is finished
/// @param j_i is like x and y in a matriz
typedef struct t_variables
{
	void *mlx;
	void *window;
	
	int		fd;
	int		heightmap;
	int		widthmap;
	int		i;
	int		j;
	int		collectables;
	int		total_collectable;
	int		moves;
	int 	p_count;
	int		e_count;
	int		c_count;	
	int		current_frame;
	
	int		flag;
	int		cflag;
	int		enflag;
	int		enemy;
	int		gifflag;
	int		finish;
	
	char	**map;
		
	void	*floor;
	void	*wall;
	void	*wallg;
	void 	*m1;
	void	*m2;
	void	*m3;
	void	*m4;
	void	*m5;
	void	*m6;
	void	*player1;
	void	*player2;
	void	*player3;
	void	*colectable;
	void	*colectable2;
	void	*colectable3;
	void	*exit;
	void	*black;
	void	*enc;
	void	*enb;
	void	*enf;
	void	*enddead;
	void	*endwin;
	void	**gif;

	time_t start_time;
} t_idk;

int		map_reading(t_idk *game, char *map_path);
void 	put_img_in_game(t_idk *game);
int 	controls(int key_code, t_idk *game);
int 	exit_game(t_idk *game);
int 	check_errors(t_idk *game);
void 	put_imgs_to_variables(t_idk *game);
int 	check_path(t_idk *game);
int 	render_next_frame(t_idk *game);
void 	load_frames(t_idk *game);
void 	put_movement(t_idk *game);
void	put_machines(t_idk *game, int height, int width);
void	put_player(t_idk *game, int height, int width);
#endif
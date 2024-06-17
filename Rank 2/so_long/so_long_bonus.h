/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 20:15:54 by prossi            #+#    #+#             */
/*   Updated: 2024/06/17 11:04:15 by maugusto         ###   ########.fr       */
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

/// @brief data from game
/// @param flag 
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
	int		strength;
	int		current_frame;
	
	int		flag;
	int		cflag;
	int		enflag;
	int		enemy;
	int		gifflag;
	
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
} t_idk;

int		map_reading(t_idk *game);
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
void	*render_next_frame_wrapper(void *arg);
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 20:15:54 by prossi            #+#    #+#             */
/*   Updated: 2024/06/03 18:05:53 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"
#include "libft/libft.h"

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
	int		moves;
	int 	player_count;
	int		exit_count;
	int		collectables_count;
	
	char	**map;
	
	void	*floor;
	void	*wall;
	void	*guy_in_wall;
	void 	*machine1;
	void	*machine2;
	void	*machine3;
	void	*machine4;
	void	*player1;
	void	*collectable;
	void	*exit;
	void	**gif;
} t_idk;

int	map_reading(t_idk *game, char **argv);
void put_img_in_game(t_idk *game);
int controls(int key_code, t_idk *game);
int exit_game(t_idk *game);
int check_errors(t_idk *game);
void put_imgs_to_variables(t_idk *game);
#endif
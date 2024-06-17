/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:49:13 by maugusto          #+#    #+#             */
/*   Updated: 2024/06/13 14:31:02 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void put_player(t_idk *game, int height, int width)
{
	int collected;
	
	collected = game->total_collectable;
	if (game->map[height][width] == 'P' && collected / 2 < game->collectables)
	{
				mlx_put_image_to_window(game->mlx,
				game->window, game->player1, width * 124, height * 124);
	}
	else if (game->map[height][width] == 'P' && collected > game->collectables / 2 && game->collectables >= 1)
	{
				mlx_put_image_to_window(game->mlx,
				game->window, game->player2, width * 124, height * 124);		
	}
	else if (game->map[height][width] == 'P' && game->collectables <= 1)
	{
				mlx_put_image_to_window(game->mlx,
				game->window, game->player3, width * 124, height * 124);		
	}
}



static void build_filename(char *filename, int frame_index) 
{
    int i;
    char *base;
	
	base = "map/gif.xpm/0.xpm";
    i = 0;
    while (base[i])
    {
        filename[i] = base[i];
        i++;
    }
    if (frame_index < 10) 
	{
        filename[12] = '0' + frame_index;
        filename[13] = '.';
		filename[i] = '\0';
    }
	else 
	{
        filename[12] = '0' + (frame_index / 10);
        filename[13] = '0' + (frame_index % 10);
		filename[14] = '.';
		filename[15] = 'x';
		filename[16] = 'p';
		filename[17] = 'm';
		filename[i + 1] = '\0';
    }
}

void load_frames(t_idk *game) 
{
    char *filename;
    int frame_index;
    int width, height;

	filename = NULL;
    frame_index = 1;
	game->gif = malloc(FRAMES * sizeof(void *));
    while (frame_index <= FRAMES) 
	{
		if (frame_index < 10) 
        	filename = malloc(18 * sizeof(char));
		else
			filename = malloc(19 * sizeof(char));
        build_filename(filename, frame_index);
        game->gif[frame_index - 1] = mlx_xpm_file_to_image(game->mlx, filename, &width, &height);
        if (!game->gif[frame_index - 1]) 
		{
            ft_printf("Erro ao carregar o frame %s\n", filename);
            exit_game(game);
        }
		free(filename);
		filename = NULL;
        frame_index++;
    }
}

int render_next_frame(t_idk *game) 
{
	if(game->gifflag == 0)
	{
		usleep(50000);
		if(game->map[1][5] == '1')
			mlx_put_image_to_window(game->mlx, game->window, game->gif[game->current_frame], 5 * 124, 1 * 124);
				game->current_frame = (game->current_frame + 1) % FRAMES;
	}
    return 0;
}
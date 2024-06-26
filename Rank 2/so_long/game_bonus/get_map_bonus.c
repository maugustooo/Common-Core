/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:52:37 by maugusto          #+#    #+#             */
/*   Updated: 2024/06/26 19:01:23 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	check_width(t_idk *game)
{
	int		height;
	int		new_width;
	char	*string;

	string = NULL;
	height = 0;
	while (height < game->heightmap)
	{
		new_width = 0;
		while (game->map[height][new_width] != '\0')
			new_width++;
		if (game->map[height][new_width - 1] == '\n')
			new_width--;
		if (new_width > game->widthmap)
			game->widthmap = new_width;
		height++;
	}
}
static int	width_of_map(char *string, t_idk *game)
{
	int width = 0;
	while (string[width] != '\0')
		width++;
	if (string[width - 1] == '\n')
		width--;
	check_width(game);
	return (width);
}

static void	find_player(t_idk *game)
{
	int	height;
	int	width;

	height = 0;
	width = 0;
	while (height < game->heightmap)
	{
		width = 0;
		while (game->map[height][width])
		{
			if (game->map[height][width] == 'P')
			{
				game->i = width;
				game->j = height;
				break ;
			}
			width++;
		}
		height++;
	}
}

static int	add_line(t_idk *game, char *line)
{
	char	**temporary;
	int		i;

	if (!line)
		return (0);
	i = 0;
	game->heightmap++;
	temporary = ft_calloc(sizeof(char *), (game->heightmap + 1));
	if (!temporary)
		return (0);
	temporary[game->heightmap] = NULL;
	while (i < game->heightmap - 1)
	{
		temporary[i] = game->map[i];
		i++;
	}
	temporary[i] = line;
	if (game->map)
		free(game->map);
	game->map = temporary;
	return (1);
}

int	map_reading(t_idk *game, char *map_path)
{
	char *readmap;

	readmap = NULL;
	game->fd = open(map_path, O_RDONLY);
	if (game->fd < 0)
	{
		game->enemy = 1;
		ft_printf("Error\n");
		exit_game(game);
	}
	while (1)
    {
        readmap = get_next_line(game->fd);
        if (!add_line(game, readmap))
            break;
    }
	close(game->fd);
	find_player(game);
	if (!game->map || !game->map[0])
		return(0);
	game->widthmap = width_of_map(game->map[0], game);
	return(1);
}

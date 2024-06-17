/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:16:39 by maugusto          #+#    #+#             */
/*   Updated: 2024/06/17 15:07:41 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	visiting(t_idk *game, int height, int width, int **visited)
{
	if (visited[height][width] || game->map[height][width] == '1' || game->map[height][width] == 'N')
		return ;
	visited[height][width] = 1;
	visiting(game, height + 1, width, visited);
	visiting(game, height - 1, width, visited);
	visiting(game, height, width + 1, visited);
	visiting(game, height, width - 1, visited);
}

static int	check_c_and_e(t_idk *game, int height, int **visited)
{
	int	path;
	int	width;

	width = 0;
	path = 1;
	while (height < game->heightmap)
	{
		width = 0;
		while (width < game->widthmap)
		{
			if ((game->map[height][width] == 'C'
				|| game->map[height][width] == 'E')
				&& !visited[height][width])
			{
				path = 0;
				break ;
			}
			width++;
		}
		if (!path)
			break ;
		height++;
	}
	return (path);
}

int	check_path(t_idk *game)
{
	int			height;
	static int	**visited;

	visited = malloc(game->heightmap * sizeof(int *));
	height = 0;
	while (height < game->heightmap)
	{
		visited[height] = ft_calloc(game->widthmap, sizeof(int));
		height++;
	}
	visiting(game, game->j, game->i, visited);
	int i = 0;
	int j = 0;
	height = 0;
	if (!check_c_and_e(game, height, visited))
	{
		ft_printf("Error\nNot all collectables or exits are reachable!\n");
		return (0);
	}
	while (height < game->heightmap)
	{
		free(visited[height]);
		height++;
	}
	free(visited);
	return (1);
}

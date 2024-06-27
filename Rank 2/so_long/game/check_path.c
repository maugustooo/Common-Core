/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:16:39 by maugusto          #+#    #+#             */
/*   Updated: 2024/06/27 14:49:45 by maugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	visiting(t_idk *game, int height, int width, int **visited)
{
	if (visited[height][width] || game->map[height][width] == '1'
		|| game->map[height][width] == 'E')
	{
		if (game->map[height][width] == 'E')
			game->exit_visit = 1;
		return ;
	}
	if (game->map[height][width] == 'C')
		game->collectables_check++;
	visited[height][width] = 1;
	visiting(game, height + 1, width, visited);
	visiting(game, height - 1, width, visited);
	visiting(game, height, width + 1, visited);
	visiting(game, height, width - 1, visited);
}

static int	check_valid(t_idk *game, int height, int **visited)
{
	int	path;
	int	width;

	path = 1;
	while (height < game->heightmap)
	{
		width = 0;
		while (width < game->widthmap)
		{
			if ((game->map[height][width] == 'C')
				&& !visited[height][width])
			{
				path = 0;
				break ;
			}
			width ++;
		}
		if (!path)
			break ;
		height++;
	}
	if (game->exit_visit == 1 && game->collectables_check < game->collectables)
		path = 0;
	return (path);
}

int	check_path(t_idk *game)
{
	int			height;
	static int	**visited;

	visited = ft_calloc(game->heightmap, sizeof(int *));
	height = 0;
	while (height < game->heightmap)
	{
		visited[height] = ft_calloc(game->widthmap, sizeof(int));
		height++;
	}
	visiting(game, game->j, game->i, visited);
	height = 0;
	while (height < game->heightmap)
	{
		free(visited[height]);
		height++;
	}
	free(visited);
	if (!check_valid(game, height, visited))
	{
		ft_printf("Error\nNot all collectables or exits are reachable!\n");
		return (0);
	}
	return (1);
}

#include "../so_long.h"

static int path_checker(t_idk *game, int height, int width)
{
	if (height <= 0 || height >= game->heightmap - 1 
	|| width <= 0 || width >= game->widthmap - 1)
        return (1);
	if(game->map[height][width] == 'E'|| game->map[height][width] == 
		'P' || game->map[height][width] == 'C')
	{	
		if((game->map[height + 1][width] != '0') &&
			(game->map[height - 1][width] != '0') &&
			(game->map[height][width + 1] != '0') &&
			(game->map[height][width - 1] != '0'))
			{
				return(0);
			}
	}
	return(1);
}

static void	check_path(t_idk *game)
{
	int	height;
	int	width;

	height = 0;
	while (height < game->heightmap - 1)
	{
		width = 0;
		while (width <= game->widthmap - 1)
		{
			if(!(path_checker(game, height, width)))
			{
				ft_printf("\nError\nSomething is wrong!\n");
				ft_printf("either player, exit or collectable path issue\n");
				exit_game(game);
			}
			width++;
		}
		height++;
	}
}

static void count_checker(t_idk *game, int height, int width)
{
	if(game->map[height][width] != '1' &&
		game->map[height][width] != '0'&&
		game->map[height][width] != 'C' &&
		game->map[height][width] != 'E' && 
		game->map[height][width] != 'P' &&
		game->map[height][width] != '\n')
	{
		ft_printf("\nError Here!%c\n", game->map[height][width]);
		exit_game(game);
	}
	if(game->map[height][width] == 'P')
		game->player_count ++;
	if(game->map[height][width] == 'E')
		game->exit_count ++;
	if(game->map[height][width] == 'C')
		game->collectables_count ++;
}

static void	check_count_and_rectangular(t_idk *game)
{
	int	height;
	int	width;

	height = 0;
	while (height < game->heightmap - 1)
	{
		width = 0;
		while (width <= game->widthmap)
		{
			count_checker(game, height, width);
			width++;
		}
		height++;
	}
	if (!(game->player_count == 1 && game->exit_count == 1 && game->collectables_count >= 1))
	{
		ft_printf("\nError\nSomething is wrong!\n");
		ft_printf("either player, exit or collectable issue\n");
		exit_game(game);
	}
	if(game->heightmap == game->widthmap)
	{
		ft_printf("Bruh the map isn't rectangular");
		exit_game(game);
	}
}

int check_errors(t_idk *game)
{
	int i;
	int j;

	i = game->widthmap;
	j = 0;
	while (j < i)
	{
		if(!(game->map[0][j] == '1' && game->map[game->heightmap - 1][j] == '1'))
			return(0);
		j++;
	}
	i = game->heightmap;
	j = 0;
	while (j < i)
	{
		if(!(game->map[j][0] == '1' && game->map[j][game->widthmap - 1] == '1'))
			return(0);
		j++;
	}
	check_path(game);
	check_count_and_rectangular(game);
	return(1);
}

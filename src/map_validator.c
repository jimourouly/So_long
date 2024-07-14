/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <jroulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 13:37:36 by jroulet           #+#    #+#             */
/*   Updated: 2024/07/14 15:55:46 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

static char	**copy_grid(t_game *game)
{
	int		i;
	char	**map;

	i = 0;
	map = ft_calloc((game->map.lines + 1), sizeof(char *));
	if (!map)
		error_close(game, MALLOC_FAILED);
	while (i < game->map.lines)
	{
		map[i] = ft_strdup(game->map.map[i]);
		if (!map[i])
		{
			ft_free_char_tab(map);
			error_close(game, MALLOC_FAILED);
		}
		i += 1;
	}
	return (map);
}

int	floodfill(t_map *map, t_coord current, char **temp_grid)
{
	static int	coins = 0;
	static int	exit_found = 0;

	if (temp_grid[current.yaxis][current.xaxis] == WALL)
		return (0);
	else if (temp_grid[current.yaxis][current.xaxis] == COINS)
		coins += 1;
	else if (temp_grid[current.yaxis][current.xaxis] == EXIT)
		exit_found = 1;
	temp_grid[current.yaxis][current.xaxis] = WALL;
	floodfill(map, (t_coord){current.xaxis + 1, current.yaxis}, temp_grid);
	floodfill(map, (t_coord){current.xaxis - 1, current.yaxis}, temp_grid);
	floodfill(map, (t_coord){current.xaxis, current.yaxis + 1}, temp_grid);
	floodfill(map, (t_coord){current.xaxis, current.yaxis - 1}, temp_grid);
	return (coins == map->coins && exit_found);
}

void	is_path_ok(t_game *game)
{
	char	**temp_grid;

	temp_grid = copy_grid(game);
	if (!floodfill(&game->map, game->map.playerpos, temp_grid))
	{
		ft_free_char_tab(temp_grid);
		error_close(game, FLOODFILL);
	}
	ft_free_char_tab(temp_grid);
}

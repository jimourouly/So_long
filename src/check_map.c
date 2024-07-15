/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <jroulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 12:37:58 by jroulet           #+#    #+#             */
/*   Updated: 2024/07/15 13:06:11 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	error_catcher(t_game *game)
{
	if (game->map.exit != 1)
		error_close(game, MAP_EXITS);
	if (game->map.coins < 1)
		error_close(game, MAP_COINS);
	if (game->map.player != 1)
		error_close(game, MAP_PLAYER);
}

void	check_item(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map.lines)
	{
		j = -1;
		while (++j < game->map.columns)
		{
			if (!ft_c_in_s(VALID_ITEM, game->map.map[i][j]))
				error_close(game, MAP_ITEM);
			if (game->map.map[i][j] == EXIT)
				game->map.exit += 1;
			else if (game->map.map[i][j] == COINS)
				game->map.coins += 1;
			else if (game->map.map[i][j] == PLAYER)
			{
				game->map.player += 1;
				game->map.playerpos = (t_coord){j, i};
			}
		}
	}
	ft_printf("end check_item\n");
	error_catcher(game);
}

int	wall_ok(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->lines)
	{
		if (map->map[i][0] != WALL || map->map[i][map->columns - 1] != WALL)
			return (0);
	}
	while (++i < map->columns)
	{
		if (map->map[0][i] != WALL || map->map[map->lines -1][i] != WALL)
			return (0);
	}
	return (1);
}

int	is_rectangle(t_game *game)
{
	size_t	len;
	size_t	i;

	len = game->map.columns;
	i = 0;
	while (game->map.map[i] != NULL)
	{
		if (len != ft_strlen(game->map.map[i]))
			return (0);
		i += 1;
	}
	return (1);
}

void	map_check(t_game *game)
{
	if (!is_rectangle(game))
		error_close(game, MAP_FORMAT);
	check_item(game);
	if (!wall_ok(&game->map))
		error_close(game, MAP_WALLS);
	is_path_ok(game);
}

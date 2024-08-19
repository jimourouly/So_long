/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_update.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <jroulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 14:29:24 by jroulet           #+#    #+#             */
/*   Updated: 2024/08/19 19:05:59 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	draw_player(t_game *game)
{
	game->moves += 1;
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->tiles.player,
		IMG_SIZE * game->map.playerpos.xaxis,
		IMG_SIZE * game->map.playerpos.yaxis);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->tiles.wall, 0, 0);
	ft_printf("move : %d \n", game->moves);
}

void	next_tile(t_game *game)
{
	if (game->map.map[game->map.playerpos.yaxis]
		[game->map.playerpos.xaxis] == COINS)
	{
		game->map.map[game->map.playerpos.yaxis]
		[game->map.playerpos.xaxis] = FLOOR;
		game->map.coins -= 1;
		return ;
	}
	if (game->map.map[game->map.playerpos.yaxis][game->map.playerpos.xaxis]
			== EXIT && game->map.coins == 0)
	{
		ft_printf(WIN);
		exit_game(game);
	}
}

void	change_past_tile(t_game *game)
{
	if (game->map.map[game->map.playerpos.yaxis]
		[game->map.playerpos.xaxis] == EXIT)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->tiles.exit,
			IMG_SIZE * game->map.playerpos.xaxis,
			IMG_SIZE * game->map.playerpos.yaxis);
	}
	else
		mlx_put_image_to_window(
			game->mlx_ptr, game->win_ptr, game->tiles.floor,
			IMG_SIZE * game->map.playerpos.xaxis,
			IMG_SIZE * game->map.playerpos.yaxis);
}

void	move_player(t_game *game, int yaxis, int move)
{
	if (yaxis)
	{
		if (game->map.map[game->map.playerpos.yaxis]
			[game->map.playerpos.xaxis + move] == WALL)
			return ;
		change_past_tile(game);
		game->map.playerpos.xaxis += move;
	}
	else
	{
		if (game->map.map[game->map.playerpos.yaxis + move]
			[game->map.playerpos.xaxis] == WALL)
			return ;
		change_past_tile(game);
		game->map.playerpos.yaxis += move;
	}
	next_tile(game);
	draw_player(game);
}

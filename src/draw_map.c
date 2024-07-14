/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <jroulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 16:04:24 by jroulet           #+#    #+#             */
/*   Updated: 2024/07/14 16:11:10 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

static void	error_xpm(t_game *game)
{
	if (!game->tiles.wall)
		error_close(game, MLX_WALL);
	if (!game->tiles.floor)
		error_close(game, MLX_FLOOR);
	if (!game->tiles.player)
		error_close(game, MLX_PLAYER);
	if (!game->tiles.coin)
		error_close(game, MLX_COINS);
	if (!game->tiles.exit)
		error_close(game, MLX_EXIT);
}

static void	open_img(t_game *game)
{
	int	img_size;

	img_size = IMG_SIZE;
	game->tiles.wall = mlx_xpm_file_to_image(game->mlx_ptr,
			IMG_WALL, &img_size, &img_size);
	game->tiles.floor = mlx_xpm_file_to_image(game->mlx_ptr,
			IMG_FLOOR, &img_size, &img_size);
	game->tiles.player = mlx_xpm_file_to_image(game->mlx_ptr,
			IMG_PLAYER, &img_size, &img_size);
	game->tiles.coin = mlx_xpm_file_to_image(game->mlx_ptr,
			IMG_COINS, &img_size, &img_size);
	game->tiles.exit = mlx_xpm_file_to_image(game->mlx_ptr,
			IMG_EXIT, &img_size, &img_size);
	error_xpm(game);
}

void	draw_tile(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map.lines)
	{
		j = -1;
		while (++j < game->map.columns)
		{
			if (game->map.map[i][j] == WALL)
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->tiles.wall, IMG_SIZE * j, IMG_SIZE * i);
			else if (game->map.map[i][j] == COINS)
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->tiles.coin, IMG_SIZE * j, IMG_SIZE * i);
			else if (game->map.map[i][j] == EXIT)
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->tiles.exit, IMG_SIZE * j, IMG_SIZE * i);
			else
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->tiles.floor, IMG_SIZE * j, IMG_SIZE * i);
		}
	}
	draw_player(game);
}

void	draw_map(t_game *game)
{
	open_img(game);
	draw_tile(game);
}

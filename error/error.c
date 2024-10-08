/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <jroulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 13:55:05 by jroulet           #+#    #+#             */
/*   Updated: 2024/08/19 18:55:30 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	erase_map(t_game *game)
{
	if (game->tiles.wall)
	{
		mlx_destroy_image(game->mlx_ptr, game->tiles.wall);
		game->tiles.wall = NULL;
	}
	if (game->tiles.floor)
	{
		mlx_destroy_image(game->mlx_ptr, game->tiles.floor);
		game->tiles.floor = NULL;
	}
	if (game->tiles.player)
	{
		mlx_destroy_image(game->mlx_ptr, game->tiles.player);
		game->tiles.player = NULL;
	}
	if (game->tiles.coin)
	{
		mlx_destroy_image(game->mlx_ptr, game->tiles.coin);
		game->tiles.coin = NULL;
	}
	if (game->tiles.exit)
	{
		mlx_destroy_image(game->mlx_ptr, game->tiles.exit);
		game->tiles.exit = NULL;
	}
}

void	exit_destroy(t_game *game)
{
	if (!game)
		return ;
	erase_map(game);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	if (game->map.map)
		ft_free_char_tab(game->map.map);
}

void	error_close(t_game *game, char *message)
{
	exit_destroy(game);
	ft_putstr_fd("ERROR : ", STDERR_FILENO);
	ft_putendl_fd(message, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

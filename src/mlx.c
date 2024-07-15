/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <jroulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 14:23:31 by jroulet           #+#    #+#             */
/*   Updated: 2024/07/15 15:03:48 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	start_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		error_close(game, MLX_INITIALIZE);
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->map.columns * IMG_SIZE,
			game->map.lines * IMG_SIZE, "so_long");
	if (!game->win_ptr)
		error_close(game, MLX_WINDOWS);
}

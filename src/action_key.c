/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <jroulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 14:13:44 by jroulet           #+#    #+#             */
/*   Updated: 2024/08/10 13:20:33 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	exit_game(t_game *game)
{
	exit_destroy(game);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

int	pressed(int key, t_game *game)
{
	if (key == KEY_ESC)
		exit_game(game);
	else if (key == KEY_W || key == KEY_UP)
		move_player(game, 0, -1);
	else if (key == KEY_A || key == KEY_LEFT)
		move_player(game, 1, -1);
	else if (key == KEY_S || key == KEY_DOWN)
		move_player(game, 0, 1);
	else if (key == KEY_D || key == KEY_RIGHT)
		move_player(game, 1, 1);
	return (EXIT_SUCCESS);
}

void	action_key(t_game *game)
{
	mlx_hook(game->win_ptr, KEY_EVENT, (1L << 0), pressed, game);
	mlx_hook(game->win_ptr, DELETE_EVENT, (1L << 17), exit_game, game);
	mlx_loop(game->mlx_ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <jroulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 11:23:22 by jroulet           #+#    #+#             */
/*   Updated: 2024/08/10 12:18:24 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	ac_check(int ac, char **av)
{
	if (ac != 2)
		error_close(NULL, NBR_AC);
	if (*av[1] == '\0')
		error_close(NULL, MAP);
}

int	main(int ac, char **av)
{
	t_game	game;

	ac_check(ac, av);
	game = gameinit();
	create_map(av[1], &game);
	map_check(&game);
	start_mlx(&game);
	draw_map(&game);
	action_key(&game);
	return (EXIT);
}

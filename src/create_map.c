/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <jroulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 12:12:37 by jroulet           #+#    #+#             */
/*   Updated: 2024/08/11 14:41:24 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

bool	check_file_extension(const char *filepath)
{
	char	*dot;

	if (filepath == NULL)
		return (false);
	dot = ft_strrchr(filepath, '.');
	if (!dot || dot == filepath || *(dot + 1) == '\0')
	{
		return (false);
	}
	if (ft_strcmp(dot, ".ber") == 0)
		return (true);
	else
		return (false);
}

static void	get_nbr_lines(char *mappath, t_game *game)
{
	int		i;
	int		fd;
	char	*tmp;

	i = 0;
	fd = open(mappath, O_RDONLY);
	if (fd == -1)
		error_close(game, FILE_OPEN);
	tmp = get_next_line(fd);
	while (tmp)
	{
		i += 1;
		free(tmp);
		tmp = get_next_line(fd);
	}
	if (i == 0)
		error_close(game, FILE_EMPTY);
	game->map.lines = i;
	close(fd);
}

static void	get_lines(char *mappath, t_game *game)
{
	int	fd;
	int	i;

	fd = open(mappath, O_RDONLY);
	if (fd == -1)
		error_close(game, FILE_OPEN);
	i = 0;
	while (i < game->map.lines)
		game->map.map[i++] = get_next_line(fd);
	game->map.map[i] = NULL;
	close (fd);
	i = 0;
	while (i < (game->map.lines - 1))
	{
		game->map.map[i] = trim_free(game->map.map[i], "\n");
		if (!game->map.map[i])
			error_close(game, MALLOC_FAILED);
		i += 1;
	}
	game->map.columns = ft_strlen(game->map.map[0]);
}

void	create_map(char *mappath, t_game *game)
{
	if (!check_file_extension(mappath))
		error_close(game, FILE_EXTENSION);
	get_nbr_lines(mappath, game);
	game->map.map = malloc((game->map.lines +1) * sizeof(char *));
	ft_printf("malloc creatmap %p\n", game->map.map);
	if (!game->map.map)
		error_close(game, MALLOC_FAILED);
	get_lines(mappath, game);
}

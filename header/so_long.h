/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <jroulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 11:24:24 by jroulet           #+#    #+#             */
/*   Updated: 2024/07/14 16:23:33 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define VALID_ITEM "ECP01"

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_DOWN 65364
# define KEY_ESC 65307

# define IMG_WALL "../assets/wall.xpm"
# define IMG_FLOOR "../assets/floor.xpm"
# define IMG_PLAYER "../assets/player.xpm"
# define IMG_COINS "../assets/coin.xpm"
# define IMG_EXIT "../assets/exit.xpm"
# define IMG_SIZE 64


# include "../header/error.h"
# include <stdbool.h>

# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
# include "../GNL/get_next_line.h"

# define FLOOR '0'
# define WALL '1'
# define EXIT 'E'
# define COINS 'C'
# define PLAYER 'P'

# define KEY_EVENT 2
# define DELETE_EVENT 17
# define WIN "bravo"

typedef struct s_coord
{
	int			xaxis;
	int			yaxis;
}				t_coord;

typedef struct s_map
{
	char		**map;
	int			lines;
	int			columns;
	int			coins;
	int			exit;
	int			player;
	t_coord		playerpos;
}				t_map;

typedef struct s_tiles
{
	void		*wall;
	void		*floor;
	void		*player;
	void		*coin;
	void		*exit;
}				t_tiles;

typedef struct s_game
{
	t_map		map;
	void		*mlx_ptr;
	void		*win_ptr;
	t_tiles		tiles;
	int			moves;
}				t_game;


static inline t_game	gameinit(void)
{
	return ((t_game)
	{
		.map.map = NULL,
		.map.lines = 0,
		.map.columns = 0,
		.map.coins = 0,
		.map.exit = 0,
		.map.player = 0,
		.tiles.coin = NULL,
		.tiles.exit = NULL,
		.tiles.floor = NULL,
		.tiles.player = NULL,
		.tiles.wall = NULL,
		.moves = 0,
	});
}

void	create_map(char *mappath, t_game *game);
void	check_path(t_game *game);
void	map_check(t_game *game);

void	start_mlx(t_game *game);
void	draw_map(t_game *gane);
void	move_player(t_game *game, int yaxis, int move);
void	draw_player(t_game *game);
void	action_key(t_game *game);
int		exit_game(t_game *game);

void	error_close(t_game *game, char *message);
void	exit_destroy(t_game *game);
void	is_path_ok(t_game *game);

#endif

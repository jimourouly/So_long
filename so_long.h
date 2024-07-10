/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <jroulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:14:26 by jroulet           #+#    #+#             */
/*   Updated: 2024/07/08 17:20:51 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "mlx_linux/mlx.h"
# include "./GNL/get_next_line.h"
# include <math.h>

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;


typedef struct s_map
{
	int		type;
	int		x;
	int		y;
	int		visited;

}				t_map;

void	ft_put_pixel(t_img *img, int x, int y, int color);

void	draw_circle (t_img *img, int x, int y, int size, int color);
void	draw_triangle (t_img *img, int x, int y, int size, int color);
void	draw_square (t_img *img, int x, int y, int size, int color);

int		ft_columns_count(char *line);
int		checkmapdim(char *mappath);
int		ft_lines_count (char *mappath);
int		**arraymaker (char *mappath, int nbrlines);
void	printarray (int **array, int nbrlines);
void	returnpos(int **array, int nbrlines, t_map *pos, int item);
int		ft_coin_count(int **array, int nbrlines, int nbrcol);
int		ft_rectangle(int **array, int nbrlines);

#endif

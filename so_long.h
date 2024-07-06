/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <jroulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:14:26 by jroulet           #+#    #+#             */
/*   Updated: 2024/07/06 13:41:05 by jroulet          ###   ########.fr       */
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
	int		columns;
	int		lines;

}				t_map;

void	ft_put_pixel(t_img *img, int x, int y, int color);

void	draw_circle (t_img *img, int x, int y, int size, int color);
void	draw_triangle (t_img *img, int x, int y, int size, int color);
void	draw_square (t_img *img, int x, int y, int size, int color);

int		ft_column_count(char *line);
int		checkmap(char *mappath);

#endif

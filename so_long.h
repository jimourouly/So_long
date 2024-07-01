/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:14:26 by jroulet           #+#    #+#             */
/*   Updated: 2024/07/01 15:28:13 by jim              ###   ########.fr       */
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

void	ft_put_pixel(t_img *img, int x, int y, int color);

void	draw_circle (t_img *img, int x, int y, int size, int color);
void	draw_triangle (t_img *img, int x, int y, int size, int color);
void	draw_square (t_img *img, int x, int y, int size, int color);

#endif

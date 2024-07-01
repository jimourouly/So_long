/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:14:16 by jroulet           #+#    #+#             */
/*   Updated: 2024/07/01 15:24:33 by jim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <math.h>

void	ft_put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(int ac, char **av)
{
	void	*mlx;
	void	*mlx_win;
	t_img	img;
	int		fd;
	
	if (ac != 2)
	{
		ft_putstr_fd("Error please select a map\n", 2);
		return (1);
	}
	else
	{
		fd = open(av[1], O_RDONLY);
		if (fd < 0)
		{
			ft_putstr_fd("Error opening file\n", 2);
			return (1);
		}
	}
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "HELLO");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
				&img.endian);
	ft_put_pixel(&img, 50, 50, 0xFFFF0000);
	draw_square(&img, 100, 100, 50, 0x00FF0000);
	draw_triangle(&img, 200, 200, 50, 0x0000FF00);
	draw_circle(&img, 300, 300, 50, 0x000000FF);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0,0);
	mlx_loop(mlx);

}

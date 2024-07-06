/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:14:16 by jroulet           #+#    #+#             */
/*   Updated: 2024/07/05 20:01:37 by jim              ###   ########.fr       */
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

// 1. get the map woth get next line
// 2. parse the map
// 3. control if the map is ok
// 3. draw the map
// 4. control the player
int	returnmap (char *path)
{
	int	fd;
	char	*line;
	int		i;
	int		y;

	y = 0;
	i = 0;
	
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error opening file\n", 2);
		return (1);
	}
	else
	{
		while (i < 1 )
		{
			line = get_next_line(fd);
			ft_printf("%s", line);
			y = ft_strlen(line);
			if (line == NULL)
				break;
			free(line);
			i++;
		}
		ft_printf("\n");
		ft_printf("nbr line = %d \n", i);
		ft_printf("nbr column %d\n", y);
	}
	return (i);
}
int	main(int ac, char **av)
{
	//void	*mlx;
	//void	*mlx_win;
	//t_img	img;
	int	fd;

	fd = 0;
	if (ac != 2)
	{
		ft_putstr_fd("Error please select a map\n", 2);
		return (1);
	}
	else
	{
		fd = returnmap (av[1]);
	}
	/*
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
*/
	return (0);
}

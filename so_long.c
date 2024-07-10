/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <jroulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:14:16 by jroulet           #+#    #+#             */
/*   Updated: 2024/07/08 17:21:03 by jroulet          ###   ########.fr       */
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
/*int	returnmap (char *path)
{
	int		fd;
	char	*line;
	int		i;
	int		column;

	i = 0;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error opening map\n", 2);
		return (0);
	}
	else
	{
		while (1)
		{
			line = get_next_line(fd);

			if (line == NULL)
				break;
			else
			{
				column = ft_column_count(&line);
				ft_printf("line %d nbr column %d\n",i, column );
			}
			free(line);
			i++;
		}
		//map->lines = i;
		ft_printf("\n");
		ft_printf("nbr line = %d \n", i);
		//ft_printf("nbr lines = %d \n", map->lines);
	}
	return (fd);
}*/

// add last path ==null
int	checkextension(char *path)
{
	int i;
	int	ok;


	i = 0;
	ok = 1;

	while(path[i])
	{
		if (ft_isalnum(path[i]) || path[i] == 47 || path[i] == 92)
			i++;
		if (path[i] == '.' && path[i+1] == 'b' && path[i+2] == 'e'&& path[i+3] == 'r')
		{
			ok = 1;
			break;
		}
		else
		{
			i++;
			ok = 0;
		}
	}
	return (ok);
}

int	main(int ac, char **av)
{
	//void	*mlx;
	//void	*mlx_win;
	//t_img	img;
	int	fd;
	int	**array;
	int	nbrlines;
	t_map	*player;
	t_map	*c;
	t_map	*e;

	player = malloc(sizeof(t_map));
	c = malloc(sizeof(t_map));
	e = malloc(sizeof(t_map));
	fd = open(av[1], O_RDONLY);
	nbrlines = ft_lines_count(av[1]);
	if (ac != 2 || !(checkextension(av[1])) || fd < 0)
	{
		if (ac != 2)
			ft_printf("please enter './so_long folder/file.ber\n");
		else if (!(checkextension(av[1])))
			ft_printf("Wrong filename, path or extension\n");
		else if (fd < 0)
			ft_printf("can't open filemap\n");
		return (1);
	}
	else
	{
		if (checkmapdim(av[1]))
		{
			ft_printf("dimension ok\n");
			array = arraymaker(av[1], ft_lines_count(av[1]));
			if (array == 0)
			{
				ft_printf("array must only have 1, 0, C, E and P values");
				return (0);
			}
			printarray(array, nbrlines);
			returnpos(array, nbrlines, player, 80);
			returnpos(array, nbrlines,e, 69);
			returnpos(array, nbrlines,c, 67);
			ft_rectangle(array, nbrlines);
		}
		else
		{
			ft_printf("dimension nok\n");
		}
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_shape.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:39:21 by jim               #+#    #+#             */
/*   Updated: 2024/07/01 15:07:40 by jim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_circle (t_img *img, int x, int y, int size, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (sqrt((i - size / 2) * (i - size / 2) + (j - size / 2) * (j - size / 2)) < size / 2)
				ft_put_pixel(img, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void	draw_triangle (t_img *img, int x, int y, int size, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - i)
		{
			ft_put_pixel(img, x + i, y + j, color);
			j++;
		}
		i++;
	}
}
void	draw_square (t_img *img, int x, int y, int size, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ft_put_pixel(img, x + i, y + j, color);
			j++;
		}
		i++;
	}
}
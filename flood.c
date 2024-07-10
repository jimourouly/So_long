/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <jroulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:54:03 by jroulet           #+#    #+#             */
/*   Updated: 2024/07/08 17:20:47 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		ft_coin_count(int **array, int nbrlines, int nbrcol)
{
	int	i;
	int	y;
	int	nbrcoins;

	i = 0;
	nbrcoins = 0;
	while (i < nbrlines)
	{
		y = 0;
		while (y < nbrcol)
		{
			if (array[i][y] == 'C')
				nbrcoins++;
			y++;
		}
		i++;
	}
	return (nbrcoins);
}

void	returnpos(int **array, int nbrlines, t_map *pos, int item)
{
	int	i;
	int	j;
	static int c;

	i = 0;
	c = 0;
	if (item == 'C')
		c++;
	while (i < nbrlines)
	{
		j = 0;
		while (j < nbrlines)
		{
			if (array[i][j] == item)
			{
				pos->x = j;
				pos->y = i;
			}
			j ++;
		}
		i++;
	}
	ft_coin_count(array, nbrlines, nbrlines);
	ft_printf("%c[%d] x%d y%d\n", item, c, pos->x, pos->y);

}

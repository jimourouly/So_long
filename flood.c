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


void	returnpos(int **array, int nbrlines, t_map *pos, int item)
{
	int	i;
	int	j;

	i = 0;
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
	ft_printf("pos %c y = %d\n", item, pos->y);
	ft_printf("pos %c x = %d\n", item , pos->x);

}

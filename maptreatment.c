/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maptreatment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <jroulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 10:28:37 by jroulet           #+#    #+#             */
/*   Updated: 2024/07/06 13:43:19 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_column_count(char *line)
{
	int	count;

	count = ft_strlen(line);
	return (count);

}


// check number of line
// check number of column
// check if column and line are equal
int	checkmap(char *mappath)
{
	char	*line;
	int		fd;
	//int		lines;
	int		columns;
	int		i;

	i = 1;
	fd = open(mappath, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		else
		{
			columns = ft_column_count(line);
			ft_printf("line %d columns %d\n", i, columns);
		}
		i++;
	}
	return (1);
}

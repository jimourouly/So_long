/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maptreatment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <jroulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 10:28:37 by jroulet           #+#    #+#             */
/*   Updated: 2024/07/06 14:42:55 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_columns_count(char *line)
{
	int	count;

	count = ft_strlen(line);
	return (count);

}

int	ft_lines_count (char *mappath)
{
	char	*line;
	int		i;
	int		fd;

	i = 0;
	fd = open(mappath, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		else
			i++;
		free(line);
	}
	ft_printf("i = %d\n", i);
	return (i);
}


// check number of line
// check number of column
// check if column and line are equal
int	checkmapdim(char *mappath)
{
	char	*line;
	int		fd;
	int		columns;
	int		lines;
	int		i;

	i = 1;
	lines = (ft_lines_count(mappath));
	ft_printf("lines = %d\n", lines);
	fd = open(mappath, O_RDONLY);
	while (i <= lines)
	{
		line = get_next_line(fd);
		columns = ft_columns_count(line);
		if (columns != lines)
			return (0);
		i++;
		free(line);
	}
	return (1);
}

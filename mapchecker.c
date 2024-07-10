/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapchecker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <jroulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 10:28:37 by jroulet           #+#    #+#             */
/*   Updated: 2024/07/08 16:00:24 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_columns_count(char *line)
{
	int	count;

	count = ft_strlen(line);
	return (count);
}

int ft_rectangle(int **array, int nbrlines)
{
//check if map is rectangle or swaure
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
	return (i);
}


void	printarray (int **array, int nbrlines)
{
	int	i;
	int	j;

	ft_printf("\n\n\narray\n");
	i = 0;
	while (i < nbrlines)
	{
		j = 0;
		while (j < nbrlines)
		{
			ft_printf("%c ", array[i][j]);
			j ++;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("END array\n");
}

void	mintomaj(int **array, int nbrlines)
{
	int i;
	int	y;

	i = 0;
	while (i < nbrlines)
	{
		y = 0;
		while (y < nbrlines)
		{
			if (array[i][y] == 'c')
				array[i][y] = (array[i][y] - 32);
			if (array[i][y] == 'e')
				array[i][y] = (array[i][y] - 32);
			if (array[i][y] == 'p')
				array[i][y] = (array[i][y] - 32);
			y++;
		}
		i ++;
	}
}

int	checkpce(int **array, int nbrlines)
{
	ft_printf("checkPCE\n");
	int i;
	int	y;
	int	countPCE[3];

	countPCE[0] = 0;
	countPCE[1] = 0;
	countPCE[2] = 0;

	i = 0;
	while (i < nbrlines)
	{
		y = 0;
		while (y < nbrlines)
		{
			if (array[i][y] == 'c' || array[i][y] == 'C')
				countPCE[0]++;
			if (array[i][y] == 'e' || array[i][y] == 'E')
				countPCE[1]++;
			if (array[i][y] == 'p'|| array[i][y] == 'P')
				countPCE[2]++;
			y++;
		}
		i ++;
	}
	if (countPCE[0] < 1 || countPCE[1] != 1 || countPCE[2] != 1 )
		return(0);
	return (1);

}

// check max 1 p and 1 e
// check doable

int	checkwall(int **array, int nbrlines)
{
	int	i;

	i = 1;
	while (i < nbrlines)
	{
		if (array[0][i] != 49)
			return (0);
		if (array[i][0] != 49)
			return (0);
		if (array[nbrlines - 1][nbrlines - i] != 49)
			return (0);
		if (array[nbrlines - i ][nbrlines - 1] != 49)
			return (0);
		i ++;
	}
	return (1);
}

int	checkmapcontent(char c)
{
	int ok;

	ok = 0;
	if (c == 99 || c == 101 || c == 112)
		c = (c - 32);
	if (c == 48 || c == 49 || c == 67 || c == 69 || c == 80)
		ok = 1;
	return (ok);
}


int	**arraymaker (char *mappath, int nbrlines)
{
	int		fd;
	char	*line;
	int		lines;
	int		i;
	int		j;
	int		**array;

	i = 0;
	array = (int **)malloc(nbrlines * sizeof(int *));
	if (array == NULL)
	{
		ft_printf("Error allocating memory\n");
		return (0);
	}
	fd = open(mappath, O_RDONLY);
	lines = ft_lines_count(mappath);
	while (i < (lines))
	{
		j = 0;
		line = get_next_line(fd);
		array[i] = (int *)malloc(nbrlines * sizeof(int));
		while (j < nbrlines)
		{
			if (line == NULL)
				break;
			if (checkmapcontent(line[j]))
			{
				array[i][j] = (int)(line[j]);
			}
			else
				return (0);
			j++;
		}
		i++;
		free (line);

	}
	if (!(checkwall(array, lines)))
		ft_printf("map must be between wall\n");
	else
		ft_printf("wall ok\n");
	if (!(checkpce(array, nbrlines)))
		ft_printf("CPE NOK\n");
	else
		ft_printf("CPE OK\n");
	mintomaj(array, nbrlines);
	return (array);
}


int	checkmapdim(char *mappath)
{
	char	*line;
	int		fd;
	int		columns;
	int		nbrlines;
	int		i;

	i = 1;
	nbrlines = (ft_lines_count(mappath));
	fd = open(mappath, O_RDONLY);
	while (i <= nbrlines)
	{
		line = get_next_line(fd);
		columns = ft_columns_count(line);
		i++;
		free(line);
	}
	return (columns);
}

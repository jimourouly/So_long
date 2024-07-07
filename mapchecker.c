/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapchecker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <jroulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 10:28:37 by jroulet           #+#    #+#             */
/*   Updated: 2024/07/07 15:47:07 by jroulet          ###   ########.fr       */
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
	return (i);
}

void	printarray (int **array, int nbrlines)
{
	int	i;
	int	j;

	ft_printf("array\n");
	i = 0;
	while (i < nbrlines)
	{
		j = 0;
		while (j < nbrlines)
		{
			ft_printf("%d", array[i][j]);
			j ++;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("END array\n");
}

int	checkmapcontent(char c)
{
	int ok;

	ok = 0;
	if (c == 48 || c == 49 || c == 99 || c == 101 || c == 112)
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
				array[i][j] = 
				ft_printf("content ok\n");
			}
			else
				ft_printf("content nok\n");
			j++;
		}
		i++;
		free (line);
	}
	printarray(array, nbrlines);
	return (array);
}


int	checkmapdim(char *mappath)
{
	char	*line;
	int		fd;
	int		columns;
	int		lines;
	int		i;

	i = 1;
	lines = (ft_lines_count(mappath));
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
	return (columns);
}

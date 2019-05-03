/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstratu <mstratu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 19:23:16 by mstratu           #+#    #+#             */
/*   Updated: 2019/05/02 00:12:14 by mstratu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		print_map(char **map)
{
	int		i;
	int		sz;

	i = 0;
	sz = 0;
	while (map[0][sz])
		sz++;
	while (i < sz)
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
		i++;
	}
}

void	free_map(char **map, int sz)
{
	int i;

	i = 0;
	// sz = get_size(map);
	while (i < sz)
	{
		ft_memdel((void **)&(map[i]));
		i++;
	}
	ft_memdel((void **)&(map));
	ft_memdel((void **)&map);
}

// void		free_map(char **map, int sz)
// {
// 	int		i;

// // char **tmp;
// // tmp = map;

// // while(*tmp)
// // ft_strdel(&(*tmp++));
// // ft_memdel((void**)&tmp);
//  	i = 0;
// 	while (i < sz)
// 	{
// 		ft_memdel((void **)&(map[i]));
// 		i++;
// 	}
// 	ft_memdel((void **)&(map));
//  }

char		**create_map(int num)
{
	char	**grid;
	int		i;
	int		j;

	i = 0;
	grid = (char**)malloc(sizeof(char*) * num);
	while (i < num)
	{
		grid[i] = (char*)malloc(sizeof(char) * (num + 1));
		i++;
	}
	i = 0;
	while (i < num)
	{
		j = -1;
		while (++j < num + 1)
		{
			if (j == num)
				grid[i][j] = '\0';
			else
				grid[i][j] = '.';
		}
		i++;
	}
	return (grid);
}

int			new_map(int num)
{
	int	map;

	if (num < 3)
		map = 3;
	else if (num < 5)
		map = 4;
	else if (num < 7)
		map = 5;
	else if (num < 10)
		map = 6;
	else if (num < 13)
		map = 7;
	else if (num < 17)
		map = 8;
	else if (num < 21)
		map = 9;
	else if (num < 26)
		map = 10;
	else
		map = 11;
	return (map);
}

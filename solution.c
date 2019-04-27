/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstratu <mstratu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 10:32:22 by mstratu           #+#    #+#             */
/*   Updated: 2019/04/27 00:14:35 by mstratu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		place(t_coord *elem, char **map, int x, int y, char c)
{
	int  i;
	int  j;

	j = 0;
	while (j < elem->height)
	{
		i = 0;
		while (i < elem->width)
		{
			if (c == elem->name_tetr)
			{
				if (elem->tetr[j][i] == elem->name_tetr)
					map[y + j][x + i] = elem->tetr[j][i];
			}
			else
			{
				if (elem->tetr[j][i] == elem->name_tetr)
					map[y + j][x + i] = c;
			}
			i++;
		}
		j++;
	} 
}

int		try_tet(t_coord *elem, char **map, int x, int y)
{
	int i;
	int j;
	
	i = 0;
	while (i < elem->height) /*i of my pos/colum, subtracting the pos of col of tetr coming in */
	{
		j = 0;
		while (j < elem->width) //the same for rows
		{
			if (elem->tetr[i][j] == elem->name_tetr && map[y + i][x + j] != '.')
				return (0);
			j++;
		}
		i++;
	}
	place(elem, map, x, y, elem->name_tetr);
	return (1);
}

int		solve(char **map, int index, int cnt, int size, t_coord **stor)
{
	// if (stor[index] || !solve(map, index + 1, size, stor))
	int 	x;
	int 	y;
	
	y = 0;
	while (y < size - stor[index]->height + 1)
	{
		x = 0;
		while (x < size - stor[index]->width + 1)
		{
			if (try_tet(stor[index], map, x, y))
			{
				if (index == cnt - 1 || solve(map, index + 1, cnt, size, stor))
					return (1);
				else
					place(stor[index], map, x, y, '.');
			}
			x++;
		}
		y++;
	}
	return (0);
}

char    **solution(t_coord **stor, int size) /* size is the num of tetro passing in in new map*/
{
	char **map;
	int cnt;
	
	cnt = size;
	size = new_map(size);  /* here size in the size of the map, see new _map function*/
	map = create_map(size);
	while (solve(map, 0, cnt, size, stor) == 0)
	{
		free_map(map, size);
		size++; /*increase the size of map */ 
		map = create_map(size);
	}
	return(map);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstratu <mstratu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 10:32:22 by mstratu           #+#    #+#             */
/*   Updated: 2019/05/03 16:34:15 by mstratu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		place(t_coord *elem, t_map *map, t_point *point, char c)
{
	int		i;
	int		j;

	j = 0;
	while (j < elem->height)
	{
		i = 0;
		while (i < elem->width)
		{
			if (c == elem->name_tetr)
			{
				if (elem->tetr[j][i] == elem->name_tetr)
					map->d_array[point->y + j][point->x + i] = elem->tetr[j][i];
			}
			else
			{
				if (elem->tetr[j][i] == elem->name_tetr)
					map->d_array[point->y + j][point->x + i] = c;
			}
			i++;
		}
		j++;
	}
}

int			try_tet(t_coord *elem, t_map *map, t_point *p)
{
	int		i;
	int		j;

	i = 0;
	while (i < elem->height)
	{
		j = 0;
		while (j < elem->width)
		{
			if (elem->tetr[i][j] == elem->name_tetr &&
			map->d_array[p->y + i][p->x + j] != '.')
				return (0);
			j++;
		}
		i++;
	}
	place(elem, map, p, elem->name_tetr);
	return (1);
}

int			solve(t_map *map, int index, int cnt, t_coord **stor)
{
	t_point *point;

	if (index == cnt)
		return (1);

	point = (t_point*)malloc(sizeof(t_point));
	point->y = 0;
	while (point->y < map->size - stor[index]->height + 1)
	{
		point->x = 0;
		while (point->x < map->size - stor[index]->width + 1)
		{
			if (try_tet(stor[index], map, point))
			{
				if (index == cnt - 1 || solve(map, index + 1, cnt, stor))
				{
					free(point);
					return (1);
				}
				else
					place(stor[index], map, point, '.');
			}
			point->x++;
		}
		point->y++;
	}
	free(point);
	return (0);
}

void		solution(t_coord **stor, int size)
{
	int		cnt;
	t_map	*map;

	map = (t_map *)malloc(sizeof(map));
	cnt = size;
	size = new_map(size);
	map->d_array = create_map(size);
	map->size = size;
	while (solve(map, 0, cnt, stor) == 0)
	{
		free_map(map->d_array, map->size);
		map->size++;
		map->d_array = create_map(map->size);
	}
	print_map(map->d_array);
	free_map(map->d_array, map->size);
	free(*(&map));
}

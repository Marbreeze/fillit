/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_fig.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstratu <mstratu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 17:57:09 by mstratu           #+#    #+#             */
/*   Updated: 2019/05/03 16:42:45 by mstratu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			get_fig(char **save_tetro, int *val)
{
	int			x;
	int			y;

	val[0] = 3;
	val[1] = 0;
	val[2] = 3;
	val[3] = 0;
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (save_tetro[y][x] == '#')
			{
				val[1] = FT_MAX(val[1], x);
				val[0] = FT_MIN(val[0], x);
				val[3] = FT_MAX(val[3], y);
				val[2] = FT_MIN(val[2], y);
			}
			x++;
		}
		y++;
	}
}

void			init(t_coord *fig_of_hash, int *v, char letter, char **tetr)
{
	fig_of_hash->name_tetr = letter;
	fig_of_hash->height = v[3] - v[2] + 1;
	fig_of_hash->width = v[1] - v[0] + 1;
	fig_of_hash->tetr = tetr;
}

t_coord			*extract_fig(char **save_tetro, char letter)
{
	int			x;
	int			y;
	t_coord		*fig_of_hash;
	char		**tetr;
	int			v[4];

	fig_of_hash = (t_coord *)malloc(sizeof(t_coord));
	get_fig(save_tetro, v);
	tetr = ft_memalloc(sizeof(char *) * (v[3] - v[2] + 1));
	y = 0;
	while (y < v[3] - v[2] + 1)
	{
		tetr[y] = ft_strnew(v[1] - v[0] + 1);
		x = 0;
		while (x < v[1] - v[0] + 1)
		{
			tetr[y][x] = save_tetro[y + v[2]][x + v[0]];
			if (tetr[y][x] == '#')
				tetr[y][x] = letter;
			x++;
		}
		y++;
	}
	init(fig_of_hash, v, letter, tetr);
	return (fig_of_hash);
}

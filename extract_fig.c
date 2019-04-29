/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_fig.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstratu <mstratu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 17:57:09 by mstratu           #+#    #+#             */
/*   Updated: 2019/04/27 21:31:04 by mstratu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_coord	*extract_fig(char  **save_tetro, char letter)
{
    int 	x;
    int 	y;
    t_coord	*fig_of_hash;
	char	**tetr;
	int		xx[2];
	int		yy[2];

	fig_of_hash = (t_coord *)malloc(sizeof(t_coord));
	y = 0;
	xx[0] = 3;
	xx[1] = 0;
	yy[0] = 3;
	yy[1] = 0;
	fig_of_hash->name_tetr = letter;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
    	{
			if (save_tetro[y][x] == '#')
			{
				xx[1] = ft_max(xx[1], x);
				xx[0] = ft_min(xx[0], x);
				yy[1] = ft_max(yy[1], y);
				yy[0] = ft_min(yy[0], y);
			}
			x++;
    	}
		y++;
	}
	tetr = ft_memalloc(sizeof(char *) * (yy[1] - yy[0] + 1));
	y = 0;
	fig_of_hash->height = yy[1] - yy[0] + 1;
	fig_of_hash->width = xx[1] - xx[0] + 1;
	while (y < yy[1] - yy[0] + 1)
	{
		tetr[y] = ft_strnew(xx[1] - xx[0] + 1);
		x = 0;
		while (x < xx[1] - xx[0] + 1)
		{
			tetr[y][x] = save_tetro[y + yy[0]][x + xx[0]];
			if (tetr[y][x] == '#')
				tetr[y][x] = letter;
			x++;
		}
		y++;
	}
	// for (y = 0; y < yy[1] - yy[0] + 1; y++)
	// {
	// 	for (x = 0; x <  xx[1] - xx[0] + 1; x++)
	// 	{
	// 		printf("%c", tetr[y][x]);
	// 	}
	// 	printf("\n");
	// }
	// printf("Coordinates are \n");
	// for (int i = 0; i < 2; i++)
	// {
	// 	printf("%d %d\n", xx[i], yy[i]);
	// }
	// printf("___________\n");
	fig_of_hash->tetr = tetr;
	return (fig_of_hash);
}

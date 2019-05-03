/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstratu <mstratu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 21:40:10 by mstratu           #+#    #+#             */
/*   Updated: 2019/05/03 16:31:22 by mstratu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

# define FT_MIN(a, b) (a > b ? b : a)
# define FT_MAX(a, b) (a > b ? a : b)

typedef struct		s_coord
{
	int				width;
	int				height;
	char			**tetr;
	char			name_tetr;
}					t_coord;

typedef struct		s_map
{
	char			**d_array;
	int				size;
}					t_map;

typedef struct		s_tetr
{
	char			**pos;
	int				width;
	int				height;
	char			value;
}					t_tetr;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

void				print_map(char **map);
int					ft_checkhash(char **s);
void				error();
t_coord				*extract_fig(char **save_tetro, char letter);
int					ft_checker(char **str);
char				**create_map(int num);
int					new_map(int num);
void				solution(t_coord **stor, int size);
void				free_map(char **map, int sz);

#endif

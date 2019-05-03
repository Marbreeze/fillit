/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstratu <mstratu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 17:10:41 by mstratu           #+#    #+#             */
/*   Updated: 2019/04/29 21:59:32 by mstratu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_checkhash(char **s)
{
	int		i;
	int		g;
	int		docount;

	docount = 0;
	i = -1;
	while (++i < 4)
	{
		g = -1;
		while (s[i][++g] != '\0')
		{
			if (s[i][g] == '#')
			{
				if (i < 3 && s[i + 1][g] == '#')
					docount++;
				if (i > 0 && s[i - 1][g] == '#')
					docount++;
				if (g < 3 && s[i][g + 1] == '#')
					docount++;
				if (g > 0 && s[i][g - 1] == '#')
					docount++;
			}
		}
	}
	return ((docount == 6 || docount == 8) ? 1 : 0);
}

int			ft_checker(char **str)
{
	int		i;
	int		j;
	int		hash;

	i = 0;
	j = 0;
	hash = 0;
	while (i < 4)
	{
		j = 0;
		while (str[i][j] != '\0')
		{
			if ((i < 4 && str[i][j] != '.' && str[i][j] != '#') ||
			(j != 3 && i == 4 && str[i][j] != '\n'))
				return (0);
			if (str[i][j] == '#')
				hash++;
			j++;
		}
		i++;
	}
	if (hash != 4)
		return (0);
	return (1);
}

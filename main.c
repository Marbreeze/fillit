/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstratu <mstratu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 16:12:14 by mstratu           #+#    #+#             */
/*   Updated: 2019/05/03 17:48:14 by mstratu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "fillit.h"

void			error(void)
{
	ft_putstr("error\n");
	exit(0);
}

char			**read_map(int fd)
{
	char			**grid;
	int				i;
	char			*buf;

	i = 0;
	grid = ft_memalloc(sizeof(char*) * 5);
	while (i < 5)
	{
		if (get_next_line(fd, &buf) != -1)
		{
			grid[i] = ft_strdup(buf);
			free(buf);
			if (ft_strlen(grid[i]) != 4 && ft_strlen(grid[i]) != 0)
				error();
		}
		else
			error();
		i++;
	}
	// free(grid[4]);
	if (!ft_checker(grid))
		error();
	if (!ft_checkhash(grid))
		error();
	return (grid);
}

int				size_file(char *argv)
{
	int				fd;
	int				n;
	int				count;
	char			buf[BUFF_SIZE];

	count = 0;
	fd = open(argv, O_RDONLY);
	while ((n = read(fd, buf, BUFF_SIZE)) > 0)
	{
		count += n;
		if (n != 21 && n != 20)
			error();
		if (n == 21 && buf[20] != '\n')
			error();
	}
	close(fd);
	return (count);
}

int				main(int argc, char **argv)
{
	int			fd;
	int			docount;
	int			num_of_tetr;
	char		**grid;
	t_coord		**storage;

	if (argc == 2)
	{
		num_of_tetr = size_file(argv[1]);
		if ((num_of_tetr + 1) % 21 != 0)
			error();	
		num_of_tetr = (num_of_tetr + 1) / 21;
		storage = (t_coord **)malloc(sizeof(t_coord *) * num_of_tetr);
		bzero(storage, num_of_tetr);
		fd = open(argv[1], O_RDONLY);
		docount = -1;
		
		while (++docount < num_of_tetr)
		{
			grid = read_map(fd);
			storage[docount] = extract_fig(grid, (docount + 'A'));
			if (docount == num_of_tetr - 1)
				free_map(grid, 4);
			else
				free_map(grid, 5);
		}
		solution(storage, docount);
		while (--num_of_tetr >= 0)
		{
			free_map(storage[num_of_tetr]->tetr, storage[num_of_tetr]->height);
			free(storage[num_of_tetr]);
		}
		free(storage);
		close(fd);
	}
}

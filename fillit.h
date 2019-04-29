#ifndef FILLIT_H
# define FILLIT_H

# define    GOOD 1
# define    ERROR  0
# define ft_min(a, b) (a > b ? b : a)
# define ft_max(a, b) (a > b ? a : b)

# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

typedef struct		s_coord
{
    int				width;
    int				height;
	char			**tetr;
	char			name_tetr;

    
}                   t_coord;

 
typedef struct		s_map
{
    char            **d_array;
    int             size;
    
}					t_map;
typedef struct 		s_tetr
{
	char 			**pos;
	int				width;
	int				height;
	char			value;
}					t_tetr;

void				print_map(char **map);
int                 ft_checkhash(char **s);
void                error();
t_coord             *extract_fig(char **save_tetro, char letter);
int                 ft_checker(char **str);
char				**create_map(int num);
int					new_map(int num);
char    			**solution(t_coord **stor, int size);
void				free_map(char **map, int sz);

#endif

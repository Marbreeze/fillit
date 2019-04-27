#include <unistd.h>
#include <fcntl.h>
#include "fillit.h"

void    error(char *str)
{
  ft_putstr(str);
  exit(0);
}

char    **read_map(int fd)
{
  char  **grid;
  int 	i;
  char  *buf;

  i = 0;
  grid = (char**)malloc(sizeof(char*) * 5);
  while (i < 5)
  {
	  if (get_next_line(fd, &buf) != -1)
		  grid[i] = ft_strdup(buf);
	  else
		{
		  error("bad line reading");
		}
	  i++;
  }
  //thing = ft_strsplit(buf, '\n');
  // if (grid[3][0] != '\0')
	//   error("error with last newline");
  if (!ft_checker(grid))
	  error("bad connections");
  if (!ft_checkhash(grid))
	  error("bad check");
  return (grid);
}
// int		num_of_tetr(char *str)
// {
// 	int num;
// 	int size;

// 	size = size_file(str);
// 	if (size / 21 == 0)
// 	return (1);
// 	if (size % 21 == 0)
// 		num = size / 21;
// 	else 
// 		num = size / 21 + 1;
// 	return (num);
// }
int   size_file(char *argv)
{
  int fd;
  int n;
  int count;
  char buf[BUFF_SIZE];

	count = 0;
	fd = open(argv, O_RDONLY);
	while ((n = read(fd, buf, BUFF_SIZE)) > 0)
	{
		count += n;  
	}
	close(fd);
	return count;
}

int main(int argc, char **argv)
{
 	int fd;
	int docount;
  char **grid;
	char letter;
	char **sol;
  int i;
	int num_of_tetr;
	t_coord **storage;

    i = 0;
    if (argc == 2)
    {
			storage = (t_coord **)malloc(sizeof(t_coord *) * 27);
			bzero(storage, 27);
    	num_of_tetr = size_file(argv[1]) / 21 + 1;
		fd = open(argv[1], O_RDONLY);
		letter = 'A';
    	docount = 0;

		
		while (docount < num_of_tetr)
		{
			grid = read_map(fd);
			storage[docount] = extract_fig(grid, letter);
			letter++;
			docount++;
			free(grid);
		}
		sol = solution(storage, docount);
		print_map(sol);
		// for (int i = docount - 1; i >= 0; i--)
		// {
		// 	for (int y = 0; y < storage[i].y[1] - storage[i].y[0] + 1; y++)
		// 	{
		// 		for (int x = 0; x <  storage[i].x[1] - storage[i].x[0] + 1; x++)
		// 		{
		// 			printf("%c", storage[i].tetr[y][x]);
		// 		}
		// 		printf("\n");
		// 	}
		// 	printf("\n");
		// }
		close(fd);
		
    }
}

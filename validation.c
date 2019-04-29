#include "fillit.h"

int     ft_checkhash(char **s)
{
    int i;
    int g;
    int docount;

    docount = 0;
    i = 0;
    g = 0;
    if(!s)
        return 0;
    while (i < 4)
    {
        while(s[i][g] != '\0')
       	{
            if (s[i][g] == '#')
            {
				/*printf("%s \n", s[i]) ;*/
                if(i < 3 && s[i + 1][g] == '#')
                    docount++;
                if(i > 0 && s[i - 1][g] == '#')
                    docount++;
                if(g < 3 && s[i][g + 1] == '#')
                    docount++;
                if(g > 0 && s[i][g - 1] == '#')
                    docount++;
            }
            g++;
        }
        g = 0;
        i++;
    }
    if (docount == 6 || docount == 8)
        return (GOOD);
    else
        return (ERROR);
}

int     ft_checker(char **str)
{
    int i;
    int j;
    int hash;

    i = 0;
    j = 0;
    hash = 0;
  //  printf("Checking tetrimino\n\n");
    while (i < 4)
    {
        j = 0;
		while (str[i][j] != '\0')
       	{
           	if (i < 4 && str[i][j] != '.' && str[i][j] != '#')
               	return (ERROR);
            else if (j != 3 && i == 4 && str[i][j] != '\n')
               	return (ERROR);

           	if (str[i][j] == '#')
               	hash++;
           	j++;
       	}
       	i++;
	}
    if (hash != 4)
	return (ERROR);

    return (GOOD);
}

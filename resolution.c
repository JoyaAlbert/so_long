#include "so_long.h"

void printm(char	**a)
{
	int i = 0;
	while(a[i] != NULL)
	{
		ft_printf("%s\n", a[i]);
		i++;
	}
	ft_printf("\n");
}

int	resolution(char **mapcpy, char **map, int i, int j)
{
	int counter;
	int a;

	counter = 0;
	a = i;
	counter = up(i, j, a, mapcpy, counter);
	counter = down(i, j, a, mapcpy, counter);
	i = 0;
	counter = lastcheck(i, j, a, mapcpy, counter);
	if (counter != elementsTofind(map))
		return -1;
	return 0;
}


int	player(char **map, char **mapcpy)
{
	int i;
	int j;
	i = 0;
	j = 0;

	printm(mapcpy);
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while  (map[i][j] != '\0')
		{
			if (map[i][j] == 'P')
				return (resolution(mapcpy, map, i, j));
			j++;
		}
		i++;
	}
	return (0);
}

#include "so_long.h"


int	blockedelement(char **map, int i, int j)
{
	int	counter;

	counter = 0;
	if(map[i][j + 1] == '1')
		counter++;
	if(map[i][j - 1] == '1')
		counter++;
	if(map[i - 1][j] == '1')
		counter++;
	if(map[i + 1][j] == '1')
		counter++;
	if (counter == 4)
		return (-1);
	return (0);
}

int	possibleWay(char **map)
{
	int i;
	int j;

	i = 0;
	while(map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if(map[i][j] == 'C' || map[i][j] == 'E' || map[i][j] == 'P')
			{
				if (blockedelement(map, i, j) == -1)
				{
					ft_printf("NOT SOLVABLE\n");
					return (-1);
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}
int		elementCounter(char **map, char element)
{
	int	i;
	int	j;
	int	counter;

	i = 0;
	counter = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == element)
				counter++;
			j++;
		}
		i++;
	}
	return (counter);
}
int		elementchecker(char **map)
{
	if (elementCounter(map, 'P') != 1)
	{
		ft_printf("MUST BE JUST ONE P\n");
		return (-1);
	}
	if (elementCounter(map, 'E') != 1)
	{
		ft_printf("MUST BE JUST ONE E\n");
		return (-1);
	}
	if (elementCounter(map, 'C') == 0)
	{
		ft_printf("MUST BE AT LEAST ONE C\n");
		return (-1);
	}
	if (elementCounter(map, '0') == 0)
	{
		ft_printf("MUST BE JUST ONE 0\n");
		return (-1);
	}
	return (0);
}

int elementsTofind(char **map)
{
	int	i;
	int	j;
	int	counter;

	counter = 0;
	i = 0;
	j = 0;
	while (map[i])
	{
		while  (map[i][j] != '\0')
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				counter++;
			j++;
		}
		i++;
	}
	return (counter);
}
void printm(char	**a)
{
	int i = 0;
	while(a[i])
	{
		ft_printf("%s\n", a[i]);
		i++;
	}
}
int	resolver(char **mapcpy, char **map, int i, int j, int counter)
{
	int	elNum;


	elNum =elementsTofind(map);
	ft_printf("%d  %d\n", counter, elNum);
	while(counter != elNum)
	{
		while (map[i - 1][j] != '1' && map[i][j -1] != 'x' )
		{
			i--;
			if (map[i][j] == 'C' || map[i][j] == 'E')
			{
				mapcpy = map;
				counter++;
			}
			mapcpy[i][j] = 'x';
			printm(mapcpy);
		}
		while (map[i][j -1] != '1' && map[i][j -1] != 'x' )
		{
			j--;
			if (map[i][j] == 'C' || map[i][j] == 'E')
			{
				mapcpy = map;
				counter++;
			}
			mapcpy[i][j] = 'x';
			printm(mapcpy);
			resolver(mapcpy, map, i, j, counter);
		}
		while (map[i + 1][j] != '1' && map[i][j -1] != 'x' )
		{
			i++;
			if (map[i][j] == 'C' || map[i][j] == 'E')
			{
				mapcpy = map;
				counter++;
			}
			mapcpy[i][j] = 'x';
			printm(mapcpy);
			resolver(mapcpy, map, i, j, counter);
		}
		while (map[i][j + 1] != '1' && map[i][j -1] != 'x' )
		{
			j++;
			if (map[i][j] == 'C' || map[i][j] == 'E')
			{
				mapcpy = map;
				counter++;
			}
			mapcpy[i][j] = 'x';
			printm(mapcpy);
			resolver(mapcpy, map, i, j, counter);
		}
		if(counter != elNum)
			return -1;
	}
	return 0;
}
int	player(char **map)
{
	int i;
	int j;
	char	**mapcpy;
	int	counter;

	counter  = 1;
	mapcpy = map;
	i = 0;
	j = 0;
	while (map[i])
	{
		while  (map[i][j] != '\0')
		{
			if (map[i][j] == 'P')
				return (resolver(mapcpy, map, i, j, counter));
			j++;
		}
		i++;
	}
	return (0);
}
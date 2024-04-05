#include "so_long.h"


int	blockedelement(char **map, int i, int j)
{
	int	counter;
	int ncounter;

	ncounter = 0;
	counter = 0;
	if(map[i][j + 1] == '1')
		counter++;
	if(map[i][j - 1] == '1')
		counter++;
	if(map[i - 1][j] == '1')
		counter++;
	if(map[i + 1][j] == '1')
		counter++;
	if(map[i][j + 1] == 'x')
		ncounter++;
	if(map[i][j - 1] == 'x')
		ncounter++;
	if(map[i - 1][j] == 'x')
		ncounter++;
	if(map[i + 1][j] == 'x')
		ncounter++;
	if (counter == 3) //|| (ncounter == 2 && counter ==2)
		return (-1);
	return (0);
}

int	possibleWay(char **map, char **mapcpy)
{
	/*int i;
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
	}*/
	return (player(map, mapcpy));
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
	while (map[i] != NULL)
	{
		j = 0;
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


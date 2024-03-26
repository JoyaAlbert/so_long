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
int	possibleWay(char **map, int length, int width)
{
	int i;
	int j;

	i = 0;
	while(i < length)
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
int		elementCounter(char **map, int length, int width, char element)
{
	int	i;
	int	j;
	int	counter;

	i = 0;
	counter = 0;
	while (i < length)
	{
		j = 0;
		while (j < width)
		{
			if (map[i][j] == element)
				counter++;
			j++;
		}
		i++;
	}
	return (counter);
}
int		elementchecker(char **map, int length, int width)
{
	if (elementCounter(map, length, width, 'P') != 1)
	{
		ft_printf("MUST BE JUST ONE P\n");
		return (-1);
	}
	if (elementCounter(map, length, width, 'E') != 1)
	{
		ft_printf("MUST BE JUST ONE E\n");
		return (-1);
	}
	if (elementCounter(map, length, width, 'C') == 0)
	{
		ft_printf("MUST BE AT LEAST ONE C\n");
		return (-1);
	}
	if (elementCounter(map, length, width, '0') == 0)
	{
		ft_printf("MUST BE JUST ONE 0\n");
		return (-1);
	}
	return (0);
}

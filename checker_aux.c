#include "so_long.h"


int		elementCounter(char **map, int length, int width, char element)
{
	int	i;
	int	j;
	int	counter;

	while (i < length)
	{
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
		return (-1);
	if (elementCounter(map, length, width, 'E') != 1)
		return (-1);
	else if (elementCounter(map, length, width, 'C') == 0)
		return (-1);
	else if (elementCounter(map, length, width, '0') == 0)
		return (-1);
	return (0);
}

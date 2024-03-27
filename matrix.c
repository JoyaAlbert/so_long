#include "so_long.h"

int	matrixwidth(char *map)
{
	int	i;

	i = 0;
	while (map[i] != '\n')
		i++;
	return (i + 1);
}

int	matrixlength(char *map)
{
	int i;
	int	counter;

	i = 0;
	counter = 0;
	while (map[i] != '\0')
	{
		if (map[i] == '\n')
			counter++;
		i++;
	}
	return (counter + 1);
}

void matrix_free(char **map, int i)
{
	while (i >= 0)
	{
		free(map[i]);
		i--;
	}
	free(map);
}

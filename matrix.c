#include "so_long.h"

int	matrixwidth(char *map)
{
	int		i;
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

char **matrix(int length) 
{
	char **maps;
	int i;

	i = 0;
	maps = (char **)malloc(length * sizeof(char));
	if (maps == NULL)
		return (NULL);
	while (i < length)
	{
		maps[i] = malloc(1);
		if (maps[i] == NULL)
		{
			while (i >= 0)
			{
				free(maps[i]);
				i--;
			}
			free(maps);
			return (NULL);
		}
		i++;
	}
	return (maps);
}


char	**fillmatrix(char *map_array, int length, int width, char **map)
{
	char	*aux;
	int	i;
	int	j;
	int	k;

	j = 0;
	i = 0;
	aux = malloc(width);
	if (aux == NULL)
		return (NULL);
	while (i < length)
	{
		k = 0;
		while (map_array[j] != '\n' && map_array[j] != '\0')
		{
			aux[k] = map_array[j];
			j++;
			k++;
		}
		aux[k] = '\0';
		map[i] = ft_strdup(aux);
		i++;
		j++;
	}
	return (map);
}

void matrix_free(char **map, int i)
{
	while (i >= 0)
	{
		free(map[i]);
		i--;
	}
}

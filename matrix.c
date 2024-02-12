#include "so_long.h"

int	matrixtam(int fd)
{
	int	i;
	char	*aux;

	aux = get_next_line(fd);
	i = 0;
	while (aux)
	{
		aux = get_next_line(fd);
		i++;
	}
	return(i);
}

char **matrix(int width,int length, char *aux, int fd) 
{
	char **maps;
	int i;

	i = 0;
	maps = (char **)malloc(length * sizeof(char));
	if (maps == NULL)
		return (0);
	while (aux)
	{
		maps[i] = malloc((width + 1) * sizeof(char));
		if (maps[i] == NULL)
		{
			while (i > 0)
			{
				free(maps[i]);
				i--;
			}
			free(maps);
			return (0);
		}
		i++;
		aux = get_next_line(fd);
	}
	return (maps);
}

char **fillmatrix(char **map, int fd)
{
	char	*aux;
	int		i;

	i = 0;
	aux = get_next_line(fd);
	while (aux != NULL)
	{
		map[i] = aux;
		aux = get_next_line(fd);
		i++;
	}
	return(map);
}
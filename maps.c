#include "so_long.h"
#include <string.h>

int	nameformat(char *map)
{
	int i;
	char *format;
	
	format = ".ber";
	i = 0;
	while (i <= 3)
	{
		if(map[strlen(map) -1 -i] == format[strlen(format)-1-i])
            i++;
        else
			return (-1);
	}
	return 1;
}

char **fillmatrix(char **map, int fd)
{
	char	*aux;
	int		i;

	aux = get_next_line(fd);
	while (aux != NULL)
	{
		map[i] = aux;
		i++;
		aux = get_next_line(fd);
	}
	return(map);
}

char **matrix(int width, char *aux, int fd) 
{
	char **maps;
	int i;

	i = 0;
	maps = (char **)malloc(width * sizeof(char));
	if (maps == NULL)
		return (0);
	while (!aux)
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


int	mapchecker(char	*map_name)
{
	char	*aux;
	char	**map;
	int	i;

	i = 0;
	if (nameformat(map_name) == -1)
		return (-1);
	int	fd = open(map_name, O_RDONLY);
	aux = get_next_line(fd);
	map = matrix(ft_strlen(aux), aux, fd);
	close(fd); //volver a abrir y rellenar la matriz
	fd = open(map_name, O_RDONLY);
	map = fillmatrix(map,fd);
	close(fd);
	return 1;
}
int main()
{   
    char    *map_name = "test.ber";
	mapchecker(map_name);
    
}
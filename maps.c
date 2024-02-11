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

char **fillmatrix(int dato, char *mapa, char **maps)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (j < dato)
	{
		while (mapa[i] != '\n')
		{
			maps[j][i] = mapa[i];
			i++;
		}
		maps[j][i] = '\0';
		j++;
		i++;
	}
	return (maps);
}

char **matrix(int width, char *mapa, char *aux, int fd) 
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
	map = matrix(ft_strlen(aux), map_name, aux, fd);
	close(fd); //volver a abrir y rellenar la matriz
	return 1;
}
int main()
{   
    char    *map_name = "test.ber";
	mapchecker(map_name);
    
}
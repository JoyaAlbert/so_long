#include "so_long.h"

char	**mapchecker(int length, char *map_array)
{
	char	**map;
	int		width;

	width = matrixwidth(map_array);
	map = matrix(length);
	if (map == NULL)
		return (NULL);
	map = fillmatrix(map_array, length, width, map);
	if (solvableCheck(map, length, width - 2) == -1)
		return (NULL);
	if (possibleWay(map, length) == -1)
		return (NULL);
	ft_printf("SOLVABLE MAP\n");
	return (map);
}

int	nameformat(char *map)
{
	int i;
	char *format;
	
	format = ".ber";
	i = 0;
	while (i <= 3)
	{
		if(map[ft_strlen(map) -1 -i] == format[ft_strlen(format)-1-i])
            i++;
        else
		{
			ft_printf("must be a .ber file\n");
			return (-1);
		}
	}
	return 1;
}

int		solvableCheck(char	**map, int length, int width)
{
	int i;

	i = 0;
	while (i < length)
	{
		if (map[i][0] != '1' || map[i][width] != '1')
		{
			ft_printf("NOT CLOSED BY WALLS OR DIFFERENTS WIDTHS\n");
			return (-1);
		}
		i++;
	}
	i = 0;	
	while (i <  width)
	{
		if(map[0][i] != '1' || map[length -1][i] != '1')
		{
			ft_printf("NOT CLOSED BY WALLS OR DIFFERENTS WIDTHS \n");
			return (-1);
		}
		i++;
	}
	if (elementchecker(map, length, width) == -1)
		return (-1);
	return (0);
}
char	*get_map(char *map_name)
{
	int		fd;
	char	*aux;
	char	*map_array;

	map_array = malloc(1);
	if (map_array == NULL)
		return (NULL);
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("error opening the file\n");
		return (NULL);
	}
	while (1)
	{
		aux = get_next_line(fd);
		if (!aux)
			break;
		map_array = ft_strjoin(map_array, aux);
		free(aux);
	}
	close (fd);
	return (map_array);
}

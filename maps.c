#include "so_long.h"

char	*get_map(char *map_name)
{
	int		fd;
	char	*aux;
	char	*map_array;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error opening the file\n");
		return (NULL);
	}
	map_array = malloc(1);
	if (map_array == NULL)
		return (NULL);
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
int	nameformat(char *map, int argc)
{
	int i;
	char *format;
	
	format = ".ber";
	i = 0;
	if (argc != 2)
	{
		ft_printf("To play -> ./so_long 'map file'\n");
		return (-1);
	}
	
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

char	**mapchecker(int length, char *map_array, char **mapcpy)
{
	char	**map;
	int		width;

	width = matrixwidth(map_array);
	if (width == -1)
		return (NULL);
	map = ft_split(map_array, '\n');
	if (strangechar(map) == -1)
	{
		matrix_free(map, length);
		return (NULL);
	}
	if (solvableCheck(map, length, width - 2) == -1)
	{
		matrix_free(map, length);
		return (NULL);
	}
	if (player(map, mapcpy) == -1)
	{
		printf("NOT SOLVABLE\n");
		matrix_free(map, length);
		return (NULL);
	}
	ft_printf("SOLVABLE MAP\n");
	return (map);
}



int		solvableCheck(char	**map, int length, int width)
{
	int i;

	i = 0;
	while (i < length)
	{
		if (map[i][0] != '1' || map[i][width] != '1')
		{
			ft_printf("NOT CLOSED BY WALLS\n");
			return (-1);
		}
		i++;
	}
	i = 0;	
	while (i <  width)
	{
		if(map[0][i] != '1' || map[length -1][i] != '1')
		{
			ft_printf("NOT CLOSED BY WALLS\n");
			return (-1);
		}
		i++;
	}
	if (elementchecker(map) == -1)
		return (-1);
	return (0);
}

int strangechar(char **map)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'P'
				&& map[i][j] != 'E' && map[i][j] != 'C')
			{
				ft_printf("STRANGE CHARACTER\n");
				return(-1);

			}
			j++;
		}
		i++;
	}
	return(0);
}

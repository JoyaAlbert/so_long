#include "so_long.h"


char	**mapchecker(char	*map_name)
{
	char	*aux;
	char	**map;
	int		fd;
	int		length;

	if (nameformat(map_name) == -1)
		return (NULL);
	fd = open(map_name, O_RDONLY);
	length = matrixtam(fd);
	close (fd);
	fd = open(map_name, O_RDONLY);
	aux = get_next_line(fd);
	map = matrix(ft_strlen(aux), length, aux, fd);
	close(fd);
	fd = open(map_name, O_RDONLY);
	map = fillmatrix(map,fd);
	if (map == NULL)
		return (NULL);
	close(fd);
	if (solvableCheck(map, length, ft_strlen(aux) - 2) == -1)
	{
		free(aux);
		return (NULL);
	}
	free(aux);
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
			return (-1);
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
			return (-1);
		i++;
	}
	i = 0;	
	while (i <  width)
	{
		if(map[0][i] != '1' || map[length -1][i] != '1')
			return (-1);
		i++;
	}
	if (elementchecker(map, length, width) == -1)
		return (-1);
		
	return 0;
}

#include "so_long.h"

char	**mapchecker(char	*map_name)
{
	char	*aux;
	char	**map;
	int		fd;
	int		length;
	int		i;

	i = 0;
	if (nameformat(map_name) == -1)
		return (NULL);
	fd = open(map_name, O_RDONLY);
	length = matrixtam(fd);
	close (fd);
	fd = open(map_name, O_RDONLY);
	aux = get_next_line(fd);
	map = matrix(ft_strlen(aux), length);
	//map = fillmatrix(map, fd, aux);
	close (fd);
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

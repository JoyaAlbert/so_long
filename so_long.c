#include "so_long.h"

void myleaks()
{
	system("leaks -q a.out");
}
int main()
{   
    char    *map_name = "map_files/test.ber";
	char	**map;
	char	**mapcpy;
	char	*map_array;
	int		length;

	atexit(myleaks);
	if (nameformat(map_name) == -1)
		return (0);
	map_array = get_map(map_name);
	if (map_array == NULL)
		return (0);
	length = matrixlength(map_array);
	mapcpy = ft_split(map_array, '\n');
	map = mapchecker(length, map_array, mapcpy);
	if (map == NULL)
	{
		matrix_free(mapcpy, length);
		free(map_array);
		return (0);
	}
	matrix_free(map, length -1);
	free(map_array);
	return (0);
}

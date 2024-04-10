#include "so_long.h"

void myleaks()
{
	system("leaks -q so_long");
}
int main(int argc, char **argv)
{   
	char	**map;
	char	**mapcpy;
	char	*map_array;
	int		length;

	atexit(myleaks);
	if (argc != 2)
		return NULL;
	if (nameformat(argv[1]) == -1)
		return (0);
	map_array = get_map(argv[1]);
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

#include "so_long.h"

void myleaks()
{
	system("leaks -q a.out");
}
int main()
{   
    char    *map_name = "map_files/map_0.ber";
	char	**map;
	char	*map_array;

	int		length;

	atexit(myleaks);
	if (nameformat(map_name) == -1)
		return (0);
	map_array = get_map(map_name);
	if (map_array == NULL)
		return (0);
	length = matrixlength(map_array);
	map = mapchecker(length, map_array);
	if (map == NULL)
	{
		free(map_array);
		return (0);
	}
	for (int i = 0; i < length; i++)
	{
		printf("%s\n", map[i]);
	}
	matrix_free(map, length -1);
	free(map_array);
	return (0);
}

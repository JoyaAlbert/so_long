#include "so_long.h"

void *myleaks()
{
	system("leaks -q a.out");
}
int main(int argc, char *argv[])
{   
    char    *map_name = "map_files/laby.ber";
	char	*map_array;
	char	**map;
	int		length;

	//atexit(myleaks());
	if (nameformat(map_name) == -1)
		return (0);
	map_array = get_map(map_name);
	if (map_array == NULL)
		return (0);
	length = matrixlength(map_array);
	map = mapchecker(map_name, length, map_array);
	if (map == NULL)
	{
		matrix_free(map, length);
		return (0);
	}
	for (int i = 0; i< length; i++)
		ft_printf("%s", map[i]);
    matrix_free(map, length);
	return (0);
}

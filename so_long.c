#include "so_long.h"
#include "mlx/mlx.h"

// to compile cc *.c printf/*.c gnl/*.c mlx/libmlx.a -lX11 -lXext
void myleaks()
{
	system("leaks -q so_long");
}
int mlx_start(t_list *a)
{
	int x;
	int y;

	x = (a->w -1) * 50;
	y = (a->l) * 50;
	a->mlx = mlx_init();
	textureinits(a);
	a->win = mlx_new_window(a->mlx, x, y, "So Long");
	putimgs(a);
	mlx_loop(a->mlx);
	return 0;
}
void data_taking(t_list *a, char *map_array, char **map)
{
	a->map_array = map_array;
	a->map = map;
	a->l = matrixlength(map_array);
	a->w = matrixwidth(map_array);
}
int errors_parsing(char **argv, int argc, t_list *a)
{
	char	**map;
	char	**mapcpy;
	char	*map_array;
	int		length;
	if (nameformat(argv[1], argc) == -1)
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
	data_taking(a, map_array, map);
	matrix_free(mapcpy, length);
	free(map_array);
	return 1;
}
int main(int argc, char **argv)
{   
	t_list *a;

	a = ft_calloc(1, sizeof(t_list));
	if (!a)
		return (0);
	atexit(myleaks);
	if (errors_parsing(argv, argc, a) == 0)
		return 0;
	mlx_start(a);
	matrix_free(a->map, a->l -1);
	free(a->map_array);
	return (0);
}

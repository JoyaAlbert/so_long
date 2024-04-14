#include "so_long.h"
#include "mlx/mlx.h"

// to compile cc *.c printf/*.c gnl/*.c mlx/libmlx.a -lX11 -lXext
void	myleaks(void)
{
	system("leaks -q so_long");
}

int	mlx_start(t_list *a)
{
	int	x;
	int	y;

	x = (a->w -1) * 50;
	y = (a->l) * 50;
	a->mlx = mlx_init();
	textureinits(a);
	a->win = mlx_new_window(a->mlx, x, y, "So Long");
	putimgs(a);
	mlx_key_hook(a->win, inputs, a);
	mlx_loop(a->mlx);
	return (0);
}

void	data_taking(t_list *a, char *map_array, char **map)
{
	a->map_array = map_array;
	a->map = map;
	a->l = matrixlength(map_array);
	a->w = matrixwidth(map_array);
	a->col_obt = 0;
	a->moves = 0;
	a->total_col = elementsTofind(a->map) - 1;
	a->fixed_d = 0;
	a->mv_d = 0;
	a->fixed_u = 0;
	a->mv_u = 0;
	a->fixed_r = 0;
	a->mv_r = 0;
	a->fixed_l = 0;
	a->mv_l = 0;
	e_pos(a);
}
int	errors_parsing(char **argv, int argc, t_list *a, t_reso *reso)
{
	char	**map;
	char	*map_array;
	int		length;

	if (nameformat(argv[1], argc) == -1)
		return (0);
	map_array = get_map(argv[1]);
	if (map_array == NULL)
		return (0);
	length = matrixlength(map_array);
	reso->mapcpy = ft_split(map_array, '\n');
	map = mapchecker(length, map_array, reso);
	if (map == NULL)
	{
		matrix_free(reso->mapcpy, length);
		free(map_array);
		return (0);
	}
	data_taking(a, map_array, map);
	matrix_free(reso->mapcpy, length);
	free(map_array);
	return (1);
}

void	ft_frees(t_list *a)
{
	matrix_free(a->map, a->l -1);
	free(a->map_array);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_reso	*reso;

	a = ft_calloc(1, sizeof(t_list));
	if (!a)
		return (0);
	reso = ft_calloc(1, sizeof(t_list));
	if (!reso)
		return (0);
	atexit(myleaks);
	if (errors_parsing(argv, argc, a, reso) == 0)
		return (0);
	mlx_start(a);
	return (0);
}
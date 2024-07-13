#include "so_long.h"
#include "mlx/mlx.h"

// to compile cc *.c printf/*.c gnl/*.c mlx/libmlx.a -lX11 -lXext

int	mlx_start(t_list *game_data)
{
	int	x;
	int	y;

	x = (game_data->w -1) * 50;
	y = (game_data->l) * 50;
	game_data->mlx = mlx_init();
	textureinits(game_data);
	game_data->win = mlx_new_window(game_data->mlx, x, y, "So Long");
	putimgs(game_data);
	mlx_key_hook(game_data->win, inputs, game_data);
	mlx_loop(game_data->mlx);
	return (0);
}

void	data_taking(t_list *game_data, char *map_array, char **map)
{
	game_data->map_array = map_array;
	game_data->map = map;
	game_data->l = matrixlength(map_array);
	game_data->w = matrixwidth(map_array);
	game_data->col_obt = 0;
	game_data->moves = 0;
	game_data->total_col = elementsTofind(game_data->map) - 1;
	game_data->fixed_d = 0;
	game_data->mv_d = 0;
	game_data->fixed_u = 0;
	game_data->mv_u = 0;
	game_data->fixed_r = 0;
	game_data->mv_r = 0;
	game_data->fixed_l = 0;
	game_data->mv_l = 0;
	e_pos(game_data);
}
int	errors_parsing(char **argv, int argc, t_list *game_data, t_reso *reso)
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
	data_taking(game_data, map_array, map);
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
	t_list	*game_data;
	t_reso	*reso;

	game_data = ft_calloc(1, sizeof(t_list));
	if (!game_data)
		return (0);
	reso = ft_calloc(1, sizeof(t_list));
	if (!reso)
		return (0);
	if (errors_parsing(argv, argc, game_data, reso) == 0)
		return (0);
	mlx_start(game_data);
	return (0);
}
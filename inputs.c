#include "so_long.h"
#include "mlx/mlx.h"



void	mv_up(t_list *a)
{
	a->map[a->e_y][a->e_x] = 'E';
	if (a->map[a->p_y -1][a->p_x] != '1')
	{
		if (a->map[a->p_y][a->p_x] != 'E')
			a->map[a->p_y][a->p_x] = '0';
		a->p_y--;
		a->moves++;
		ft_printf("moves %d\n", a->moves);
		if (a->map[a->p_y][a->p_x] == 'C')
			a->col_obt++;
		if (a->map[a->p_y][a->p_x] == 'E' && exitcheck(a) != 0)
		{
			ft_printf("WELL DONE\n");
			exit(0);
		}
		if (a->map[a->p_y][a->p_x] != 'E')
			a->map[a->p_y][a->p_x] = 'P';
	}
	a->mv_u++;
	putimgs(a);
}

void	mv_down(t_list *a)
{
	a->map[a->e_y][a->e_x] = 'E';
	if (a->map[a->p_y +1][a->p_x] != '1')
	{
		if (a->map[a->p_y][a->p_x] != 'E')
			a->map[a->p_y][a->p_x] = '0';
		a->p_y++;
		a->moves++;
		ft_printf("moves %d\n", a->moves);
		if (a->map[a->p_y][a->p_x] == 'C')
			a->col_obt++;
		if (a->map[a->p_y][a->p_x] == 'E' && exitcheck(a) != 0)
		{
			ft_printf("WELL DONE\n");
			exit(0);
		}
		if (a->map[a->p_y][a->p_x] != 'E')
			a->map[a->p_y][a->p_x] = 'P';
	}
	a->mv_d++;
	putimgs(a);
}

void	mv_left(t_list *a)
{
	a->map[a->e_y][a->e_x] = 'E';
	if (a->map[a->p_y][a->p_x -1] != '1')
	{
		if (a->map[a->p_y][a->p_x] != 'E')
			a->map[a->p_y][a->p_x] = '0';
		a->p_x--;
		a->moves++;
		ft_printf("moves %d\n", a->moves);
		if (a->map[a->p_y][a->p_x] == 'C')
			a->col_obt++;
		if (a->map[a->p_y][a->p_x] == 'E' && exitcheck(a) != 0)
		{
			ft_printf("WELL DONE\n");
			exit(0);
		}
		if (a->map[a->p_y][a->p_x] != 'E')
			a->map[a->p_y][a->p_x] = 'P';
	}
	a->mv_l++;
	putimgs(a);
}

void	mv_right(t_list *a)
{
	a->map[a->e_y][a->e_x] = 'E';
	if (a->map[a->p_y][a->p_x +1] != '1')
	{
		if (a->map[a->p_y][a->p_x] != 'E')
			a->map[a->p_y][a->p_x] = '0';
		a->p_x++;
		a->moves++;
		ft_printf("moves %d\n", a->moves);
		if (a->map[a->p_y][a->p_x] == 'C')
			a->col_obt++;
		if (a->map[a->p_y][a->p_x] == 'E' && exitcheck(a) != 0)
		{
			ft_printf("WELL DONE\n");
			exit(0);
		}
		if (a->map[a->p_y][a->p_x] != 'E')
			a->map[a->p_y][a->p_x] = 'P';
	}
	a->mv_r++;
	putimgs(a);
}

int	inputs(int input, t_list *a)
{
	p_pos(a);
	if (input == 48)
	{
		mlx_destroy_window(a->mlx, a->win);
		exit (0);
	}
	if (input == (int) 'W' || input == (int) 'w')
		mv_up(a);
	if (input == (int) 'S' || input == (int) 's')
		mv_down(a);
	if (input == (int) 'A' || input == (int) 'a')
		mv_left(a);
	if (input == (int) 'D' || input == (int) 'd')
		mv_right(a);
	return (1);
}

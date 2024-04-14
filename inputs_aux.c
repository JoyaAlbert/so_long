#include "so_long.h"
#include "mlx/mlx.h"

int	exitcheck(t_list *a)
{
	if (a->total_col == a->col_obt)
		return (1);
	ft_printf("You need %d more colectionables\n", a->total_col - a->col_obt);
	return (0);
}

void	p_pos(t_list *a)
{
	int	i;
	int	j;

	i = 0;
	while (a->map[i] != NULL)
	{
		j = 0;
		while (a->map[i][j] != '\0')
		{
			if (a->map[i][j] == 'P')
			{
				a->p_x = j;
				a->p_y = i;
			}
			j++;
		}
		i++;
	}
}

void	e_pos(t_list *a)
{
	int	i;
	int	j;

	i = 0;
	while (a->map[i] != NULL)
	{
		j = 0;
		while (a->map[i][j] != '\0')
		{
			if (a->map[i][j] == 'E')
			{
				a->e_x = j;
				a->e_y = i;
			}
			j++;
		}
		i++;
	}
}

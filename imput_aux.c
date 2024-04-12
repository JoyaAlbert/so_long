#include "so_long.h"
#include "mlx/mlx.h"


int inputs(int input, t_list *a)
{
    p_pos(a);
	if (input == 48)
    {
		mlx_destroy_window(a->mlx, a->win);
        exit (0);
    }
    if(input == (int)'W' || input == (int)'w')
        mv_up(a);
    if(input == (int)'S' || input == (int)'s')
        mv_down(a);
    if(input == (int)'A' || input == (int)'a')
        mv_left(a);   
    if(input == (int)'D' || input == (int)'d')
        mv_right(a);
    return 1;
}
void	p_pos(t_list *a)
{
	int i;
	int j;

	i = 0;
	while (a->map[i] != NULL)
	{
		j = 0;
		while  (a->map[i][j] != '\0')
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
	int i;
	int j;

	i = 0;
	while (a->map[i] != NULL)
	{
		j = 0;
		while  (a->map[i][j] != '\0')
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

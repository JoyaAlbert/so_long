#include "so_long.h"
#include "mlx/mlx.h"

void    textureinits(t_list *a)
{
	int w;
	int h;

	w = 50;
	h = 50;
	a->grnd = mlx_xpm_file_to_image(a->mlx, "textures/poke.xpm", &w, &h);
	a->col = mlx_xpm_file_to_image(a->mlx, "textures/c.xpm", &w, &h);
	a->escape = mlx_xpm_file_to_image(a->mlx, "textures/e.xpm", &w, &h);
	a->wall = mlx_xpm_file_to_image(a->mlx, "textures/1.xpm", &w, &h);;
	a->player = mlx_xpm_file_to_image(a->mlx, "textures/p.xpm", &w, &h);
}

void putinpos(char c, int i, int j, t_list *a)
{
	int x;
	int y;

	x = j * 50;
	y = i * 50;
	if (c == 'C')
	   mlx_put_image_to_window (a->mlx, a->win, a->col, x, y);
	else if (c == '1')
		mlx_put_image_to_window (a->mlx, a->win, a->wall, x, y);
	else if (c == 'E')
	   mlx_put_image_to_window (a->mlx, a->win, a->escape, x, y);
	else if (c == 'P')
	  mlx_put_image_to_window (a->mlx, a->win, a->player, x, y);
	else if (c == '0')
	  mlx_put_image_to_window (a->mlx, a->win, a->grnd, x, y);
}
void putimgs(t_list *a)
{
	int i;
	int j;

	i = 0;
	while(a->map[i])
	{
		j = 0;
		while (a->map[i][j] != '\0')
		{
			if (a->map[i][j] == '1')
				putinpos('1' ,i, j, a);
			else if (a->map[i][j] == '0')
				putinpos('0' ,i, j, a);
			else if (a->map[i][j] == 'C')
				putinpos('C' ,i, j, a);
			else if (a->map[i][j] == 'P')
				putinpos('P' ,i, j, a);
			else if (a->map[i][j] == 'E')
				putinpos('E' ,i, j, a);
			else
				exit(0);
			j++;
		}
		i++;
	}
}

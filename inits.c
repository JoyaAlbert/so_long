/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoya-pi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 14:51:46 by ajoya-pi          #+#    #+#             */
/*   Updated: 2024/07/14 14:51:48 by ajoya-pi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	textureinits(t_list *d)
{
	int	w;
	int	h;

	w = 50;
	h = 50;
	d->grnd = mlx_xpm_file_to_image(d->mlx, "textures/0.xpm", &w, &h);
	d->col = mlx_xpm_file_to_image(d->mlx, "textures/c.xpm", &w, &h);
	d->escape = mlx_xpm_file_to_image(d->mlx, "textures/e.xpm", &w, &h);
	d->wall = mlx_xpm_file_to_image(d->mlx, "textures/1.xpm", &w, &h);
	d->player = mlx_xpm_file_to_image(d->mlx, "textures/p1.xpm", &w, &h);
	d->player_u = mlx_xpm_file_to_image(d->mlx, "textures/up.xpm", &w, &h);
	d->player_r = mlx_xpm_file_to_image(d->mlx, "textures/right.xpm", &w, &h);
	d->player_l = mlx_xpm_file_to_image(d->mlx, "textures/left.xpm", &w, &h);
	d->escape_cp = mlx_xpm_file_to_image(d->mlx, "textures/ecp.xpm", &w, &h);
	d->escape_c = mlx_xpm_file_to_image(d->mlx, "textures/ec.xpm", &w, &h);
}

void	player_hor(int x, int y, t_list *a)
{
	if (a->mv_d != a->fixed_d)
		mlx_put_image_to_window (a->mlx, a->win, a->player, x, y);
	if (a->mv_u != a->fixed_u)
		mlx_put_image_to_window (a->mlx, a->win, a->player_u, x, y);
	if (a->mv_r != a->fixed_r)
		mlx_put_image_to_window (a->mlx, a->win, a->player_r, x, y);
	if (a->mv_l != a->fixed_l)
		mlx_put_image_to_window (a->mlx, a->win, a->player_l, x, y);
	if (a->mv_d == 0 && a->mv_r == 0 && a->mv_u == 0 && a->mv_l == 0)
		mlx_put_image_to_window (a->mlx, a->win, a->player, x, y);
	a->fixed_d = a->mv_d;
	a->fixed_u = a->mv_u;
	a->fixed_r = a->mv_r;
	a->fixed_l = a->mv_l;
}

void	putinpos(char c, int i, int j, t_list *a)
{
	int	x;
	int	y;

	x = j * 50;
	y = i * 50;
	if (c == 'C')
		mlx_put_image_to_window (a->mlx, a->win, a->col, x, y);
	else if (c == '1')
		mlx_put_image_to_window (a->mlx, a->win, a->wall, x, y);
	else if (c == 'E')
	{
		if (a->e_x == a->p_x && a->e_y == a->p_y && a->col_obt != a->total_col)
			mlx_put_image_to_window (a->mlx, a->win, a->escape_cp, x, y);
		else if (a->col_obt != a->total_col)
			mlx_put_image_to_window (a->mlx, a->win, a->escape_c, x, y);
		else if (a->col_obt == a->total_col)
			mlx_put_image_to_window (a->mlx, a->win, a->escape, x, y);
	}
	else if (c == 'P')
		player_hor(x, y, a);
	else if (c == '0')
		mlx_put_image_to_window (a->mlx, a->win, a->grnd, x, y);
}

void	putimgs(t_list *a)
{
	int	i;
	int	j;

	i = 0;
	while (a->map[i])
	{
		j = 0;
		while (a->map[i][j] != '\0')
		{
			if (a->map[i][j] == '1')
				putinpos('1', i, j, a);
			else if (a->map[i][j] == '0')
				putinpos('0', i, j, a);
			else if (a->map[i][j] == 'C')
				putinpos('C', i, j, a);
			else if (a->map[i][j] == 'P')
				putinpos('P', i, j, a);
			else if (a->map[i][j] == 'E')
				putinpos('E', i, j, a);
			j++;
		}
		i++;
	}
	mlx_string_put(a->mlx, a->win, 10, 25, 0x00, "Number of moves->");
	mlx_string_put(a->mlx, a->win, 125, 25, 0x00, ft_itoa(a->moves));
}

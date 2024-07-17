/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs_aux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoya-pi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 14:51:17 by ajoya-pi          #+#    #+#             */
/*   Updated: 2024/07/14 14:51:19 by ajoya-pi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exitcheck(t_list *a)
{
	if (a->total_col == a->col_obt)
	{
		putimgs(a);
		return (1);
	}
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

int	close_window(t_list *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (0);
}

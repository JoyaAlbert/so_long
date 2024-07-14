/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoya-pi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 14:47:46 by ajoya-pi          #+#    #+#             */
/*   Updated: 2024/07/14 14:47:50 by ajoya-pi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	lastcall(int i, int j, t_reso *re)
{
	i = 0;
	while (re->mapcpy[i])
	{
		j = 0;
		while (re->mapcpy[i][j] != '\0')
		{
			if (re->mapcpy[i][j] == 'x' &&
				(re->mapcpy[i][j + 1] != '1' && re->mapcpy[i][j + 1] != 'x'))
				return (1);
			if (re->mapcpy[i][j] == 'x' &&
				(re->mapcpy[i][j - 1] != '1' && re->mapcpy[i][j - 1] != 'x'))
				return (1);
			if (re->mapcpy[i][j] == 'x' &&
				(re->mapcpy[i - 1][j] != '1' && re->mapcpy[i - 1][j] != 'x'))
				return (1);
			if (re->mapcpy[i][j] == 'x' &&
				(re->mapcpy[i + 1][j] != '1' && re->mapcpy[i + 1][j] != 'x'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	resolution(t_reso *reso, char **map, int i, int j)
{
	int	a;

	reso->counter = 0;
	a = i;
	reso->counter = up(i, j, a, reso);
	reso->counter = down(i, j, a, reso);
	while (lastcall(i, j, reso) != 0)
		reso->counter = lastcheck(i, j, a, reso);
	if (reso->counter != elementstofind(map))
		return (-1);
	return (0);
}

int	player(char **map, t_reso *reso)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'P')
				return (resolution(reso, map, i, j));
			j++;
		}
		i++;
	}
	return (0);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

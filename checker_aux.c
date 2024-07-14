/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_aux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoya-pi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 14:52:25 by ajoya-pi          #+#    #+#             */
/*   Updated: 2024/07/14 14:52:28 by ajoya-pi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	elementcounter(char **map, char element)
{
	int	i;
	int	j;
	int	counter;

	i = 0;
	counter = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == element)
				counter++;
			j++;
		}
		i++;
	}
	return (counter);
}

int	elementchecker(char **map)
{
	if (elementcounter(map, 'P') != 1)
	{
		ft_printf("MUST BE JUST ONE P\n");
		return (-1);
	}
	if (elementcounter(map, 'E') != 1)
	{
		ft_printf("MUST BE JUST ONE E\n");
		return (-1);
	}
	if (elementcounter(map, 'C') == 0)
	{
		ft_printf("MUST BE AT LEAST ONE C\n");
		return (-1);
	}
	if (elementcounter(map, '0') == 0)
	{
		ft_printf("MUST BE JUST ONE 0\n");
		return (-1);
	}
	return (0);
}

int	elementstofind(char **map)
{
	int	i;
	int	j;
	int	counter;

	counter = 0;
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				counter++;
			j++;
		}
		i++;
	}
	return (counter);
}

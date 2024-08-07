/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoya-pi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 14:48:47 by ajoya-pi          #+#    #+#             */
/*   Updated: 2024/07/14 14:48:50 by ajoya-pi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	matrixwidth(char *map)
{
	int	i;
	int	k;
	int	size;

	i = 0;
	while (map[i] != '\n')
		i++;
	size = i;
	while (map[i] != '\0')
	{
		i++;
		k = 0;
		while (map[i] != '\n' && map[i] != '\0')
		{
			k++;
			i++;
		}
		if (k != size)
		{
			ft_printf("Error\nNOT SAME NUMBER OF ELEMENTTS FOR LINE\n");
			return (-1);
		}
	}
	return (size + 1);
}

int	matrixlength(char *map)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (map[i] != '\0')
	{
		if (map[i] == '\n')
			counter++;
		i++;
	}
	return (counter + 1);
}

void	matrix_free(char **map, int i)
{
	while (i >= 0)
	{
		free(map[i]);
		i--;
	}
	free(map);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	p = (void *)malloc(count * size);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, count * size);
	return (p);
}

int	inputsf(void)
{
	exit(0);
	return (0);
}

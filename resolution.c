#include "so_long.h"

void	printm(char **a)
{
	int	i;

	i = 0;
	while (a[i] != NULL)
	{
		ft_printf("%s\n", a[i]);
		i++;
	}
	ft_printf("\n");
}

int	resolution(t_reso *reso, char **map, int i, int j)
{
	int	a;

	reso->counter = 0;
	a = i;
	reso->counter = up(i, j, a, reso);
	reso->counter = down(i, j, a, reso);
	i = 0;
	reso->counter = lastcheck(i, j, a, reso);
	printf("%d\n", reso->counter);
	if (reso->counter != elementsTofind(map))
		return (-1);
	return (0);
}

int	player(char **map, t_reso *reso)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	printm(reso->mapcpy);
	i = 0;
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

#include "so_long.h"

void printm(char	**a)
{
	int i = 0;
	while(a[i] != NULL)
	{
		ft_printf("%s\n", a[i]);
		i++;
	}
	ft_printf("\n");
}

int	left(int i, int j, int a, char **mapcpy, int counter)
{
		while (mapcpy[i][j] != '1')
		{
			a = i;
			while (a > 0 && mapcpy[a][j] != '1')
			{
				if(mapcpy[a][j] == 'C' || mapcpy[a][j] == 'E')
					counter++;
				mapcpy[a][j] = 'x';
				a--;
			}
			a = i;
			while (mapcpy[a] && mapcpy[a][j] != '1')
			{
				if(mapcpy[a][j] == 'C' || mapcpy[a][j] == 'E')
					counter ++;
				mapcpy[a][j] = 'x';
				a++;
			}
			printm(mapcpy);
			j--;
		}
	return (counter);
}
int	right(int i, int j, int a, char **mapcpy, int counter)
{
		while (mapcpy[i][j] != '1')
		{
			a = i;
			while (a > 0 && mapcpy[a][j] != '1')
			{
				if(mapcpy[a][j] == 'C' || mapcpy[a][j] == 'E')
					counter++;
				mapcpy[a][j] = 'x';
				a--;
			}
			a = i;
			while (mapcpy[a] != NULL && mapcpy[a][j] != '1')
			{
				if(mapcpy[a][j] == 'C' || mapcpy[a][j] == 'E')
					counter++;
				mapcpy[a][j] = 'x';
				a++;
			}
			printm(mapcpy);
			j++;
		}
	return (counter);
}

int up(int i, int j, int a, char **mapcpy, int counter)
{
	int	b;

	while (mapcpy[i] != NULL)
	{
		b  = right(i, j, a, mapcpy, counter);
		if (b != counter)
			counter = b;
		b  = left(i, j, a, mapcpy, counter);
		if (b != counter)
			counter = b;
		i++;
	}
	return (b);
}
int	down(int i, int j, int a, char **mapcpy, int counter)
{
	int b;

	b = 0;
	while (i >= 0)
	{
		b  = right(i, j, a, mapcpy, counter);
		if (b != counter)
			counter = b;
		b  = left(i, j, a, mapcpy, counter);
		if (b != counter)
			counter = b;
		i--;
	}
	return (counter);
}

int	lastcheck(int i, int j, int a, char **mapcpy, int counter)
{
	while(mapcpy[i])
	{
		j = 1;
		while(mapcpy[i][j] != '\0')
		{
			if(mapcpy[i][j] == 'x' &&
				(mapcpy[i][j+1] != '1' && mapcpy[i][j+1] != 'x'))
				counter = right(i, j, a, mapcpy, counter);
			if(mapcpy[i][j] == 'x'&&
				(mapcpy[i][j-1] != '1' && mapcpy[i][j-1] != 'x'))
				counter = left(i, j, a, mapcpy, counter);
			if(mapcpy[i][j] == 'x'&&
				(mapcpy[i-1][j] != '1' && mapcpy[i-1][j] != 'x'))
				counter = up(i, j, a, mapcpy, counter);
			if(mapcpy[i][j] == 'x'&&
				(mapcpy[i+1][j+1] != '1' && mapcpy[i+1][j] != 'x'))
				counter = down(i, j, a, mapcpy, counter);
			j++;
		}
		i++;
	}
	return (counter);
}
int	resolver(char **mapcpy, char **map, int i, int j)
{
	int counter;
	int a;

	counter = 0;
	a = i;
	counter = up(i, j, a, mapcpy, counter);
	counter = down(i, j, a, mapcpy, counter);
	i = 0;
	j = 0;
	counter = lastcheck(i, j, a, mapcpy, counter);
	if (counter != elementsTofind(map))
		return -1;
	return 0;
}


int	player(char **map, char **mapcpy)
{
	int i;
	int j;
	i = 0;
	j = 0;

	printm(mapcpy);
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while  (map[i][j] != '\0')
		{
			if (map[i][j] == 'P')
				return (resolver(mapcpy, map, i, j));
			j++;
		}
		i++;
	}
	return (0);
}

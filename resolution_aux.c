#include "so_long.h"

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

	while (mapcpy[i] != NULL && mapcpy[i][j] != '1')
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
	while (i >= 0 && mapcpy[i][j] != '1')
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
	int b;

	b = j;
	while(mapcpy[i])
	{
		j = b;
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
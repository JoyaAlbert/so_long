#include "so_long.h"

int	left(int i, int j, int a, t_reso *reso)
{
	while (reso->mapcpy[i][j] != '1')
	{
		a = i;
		while (a > 0 && reso->mapcpy[a][j] != '1')
		{
			if (reso->mapcpy[a][j] == 'C' || reso->mapcpy[a][j] == 'E')
				reso->counter++;
			reso->mapcpy[a][j] = 'x';
			a--;
		}
		a = i;
		while (reso->mapcpy[a] && reso->mapcpy[a][j] != '1')
		{
			if (reso->mapcpy[a][j] == 'C' || reso->mapcpy[a][j] == 'E')
				reso->counter ++;
			reso->mapcpy[a][j] = 'x';
			a++;
		}
		printm(reso->mapcpy);
		j--;
	}
	return (reso->counter);
}

int	right(int i, int j, int a, t_reso *reso)
{
	while (reso->mapcpy[i][j] != '1')
	{
		a = i;
		while (a > 0 && reso->mapcpy[a][j] != '1')
		{
			if (reso->mapcpy[a][j] == 'C' || reso->mapcpy[a][j] == 'E')
				reso->counter++;
			reso->mapcpy[a][j] = 'x';
			a--;
		}
		a = i;
		while (reso->mapcpy[a] != NULL && reso->mapcpy[a][j] != '1')
		{
			if (reso->mapcpy[a][j] == 'C' || reso->mapcpy[a][j] == 'E')
				reso->counter++;
			reso->mapcpy[a][j] = 'x';
			a++;
		}
		printm(reso->mapcpy);
		j++;
	}
	return (reso->counter);
}

int	up(int i, int j, int a, t_reso *reso)
{
	int	b;

	while (reso->mapcpy[i] != NULL && reso->mapcpy[i][j] != '1')
	{
		b = right(i, j, a, reso);
		if (b != reso->counter)
			reso->counter = b;
		b = left(i, j, a, reso);
		if (b != reso->counter)
			reso->counter = b;
		i++;
	}
	return (b);
}

int	down(int i, int j, int a, t_reso *reso)
{
	int	b;

	b = 0;
	while (i >= 0 && reso->mapcpy[i][j] != '1')
	{
		b = right(i, j, a, reso);
		if (b != reso->counter)
			reso->counter = b;
		b = left(i, j, a, reso);
		if (b != reso->counter)
			reso->counter = b;
		i--;
	}
	return (reso->counter);
}

int	lastcheck(int i, int j, int a, t_reso *re)
{
	while (re->mapcpy[i])
	{
		while (re->mapcpy[i][j] != '\0')
		{
			if (re->mapcpy[i][j] == 'x' &&
				(re->mapcpy[i][j + 1] != '1' && re->mapcpy[i][j + 1] != 'x'))
				re->counter = right(i, j, a, re);
			if (re->mapcpy[i][j] == 'x' &&
				(re->mapcpy[i][j - 1] != '1' && re->mapcpy[i][j - 1] != 'x'))
				re->counter = left(i, j, a, re);
			if (re->mapcpy[i][j] == 'x' &&
				(re->mapcpy[i - 1][j] != '1' && re->mapcpy[i - 1][j] != 'x'))
				re->counter = up(i, j, a, re);
			if (re->mapcpy[i][j] == 'x' &&
				(re->mapcpy[i + 1][j + 1] != '1'
				&& re->mapcpy[i + 1][j] != 'x'))
				re->counter = down(i, j, a, re);
			j++;
		}
		i++;
	}
	return (re->counter);
}

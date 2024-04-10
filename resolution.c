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
				counter = left(i, j, a, mapcpy, counter);
				counter = right(i, j, a, mapcpy, counter);
			}
			a = i;
			while (mapcpy[a] && mapcpy[a][j] != '1')
			{
				if(mapcpy[a][j] == 'C' || mapcpy[a][j] == 'E')
					counter ++;
				mapcpy[a][j] = 'x';
				counter = left(i, j, a, mapcpy, counter);
				counter = right(i, j, a, mapcpy, counter);
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
				counter = right(i, j, a, mapcpy, counter);
				counter = left(i, j, a, mapcpy, counter);
			}
			a = i;
			while (mapcpy[a] != NULL && mapcpy[a][j] != '1')
			{
				if(mapcpy[a][j] == 'C' || mapcpy[a][j] == 'E')
					counter++;
				mapcpy[a][j] = 'x';
				a++;
				counter = right(i, j, a, mapcpy, counter);
				counter = left(i, j, a, mapcpy, counter);
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
int	resolver(char **mapcpy, char **map, int i, int j)
{
	int counter;
	int a;

	counter = 0;
	a = i;
	counter = up(i, j, a, mapcpy, counter);
	counter = down(i, j, a, mapcpy, counter);
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
//revisar patron x1
//				 xx1
/*
int	resolver(char **mapcpy, char **map, int i, int j, int counter)
{
	int	elNum;

	elNum = elementsTofind(map);
	ft_printf("%d  %d\n", counter, elNum);	

	while (mapcpy[i - 1][j] != '1' && mapcpy[i - 1][j] != 'x' )
	{
		i--;
		if (blockedelement(mapcpy, i, j) == -1)
			deletexs(mapcpy);	
		if (mapcpy[i][j] == 'C' || mapcpy[i][j] == 'E')
		{
			counter++;
			mapcpy[i][j] = 'x';
			deletexs(mapcpy);
		}
		else
			mapcpy[i][j] = 'x';
		if (counter == elNum)
			return 0;
		mapcpy[i][j] = 'x';
		printm(mapcpy);
	}

	while (mapcpy[i + 1][j] != '1' && mapcpy[i + 1][j] != 'x' )
	{
		i++;
		if (blockedelement(mapcpy, i, j) == -1)
			deletexs(mapcpy);
		if (mapcpy[i][j] == 'C' || mapcpy[i][j] == 'E')
		{
			counter++;
			mapcpy[i][j] = 'x';
			deletexs(mapcpy);
		}
		else
			mapcpy[i][j] = 'x';
		if (counter == elNum)
			return 0;
		printm(mapcpy);
		if (resolver(mapcpy, map, i, j, counter) == -1)
			return -1;
		else
			return (0);
	}

	while (mapcpy[i][j + 1] != '1' && mapcpy[i][j +1] != 'x' )
	{
		j++;
		if (blockedelement(mapcpy, i, j) == -1)
			deletexs(mapcpy);
		if (mapcpy[i][j] == 'C' || mapcpy[i][j] == 'E')
		{
			counter++;
			mapcpy[i][j] = 'x';
			deletexs(mapcpy);
		}
		else
			mapcpy[i][j] = 'x';
		if (counter == elNum)
			return 0;
		mapcpy[i][j] = 'x';
		printm(mapcpy);
		if (resolver(mapcpy, map, i, j, counter) == -1)
			return -1;
		else
			return (0);
	}
	while (mapcpy[i][j -1] != '1' && mapcpy[i][j - 1] != 'x' )
	{
		j--;
		if (blockedelement(mapcpy, i, j) == -1)
			deletexs(mapcpy);
		if (mapcpy[i][j] == 'C' || mapcpy[i][j] == 'E')
		{
			counter++;
			mapcpy[i][j] = 'x';
			deletexs(mapcpy);
		}
		else
			mapcpy[i][j] = 'x';
		if (counter == elNum)
			return 0;
		mapcpy[i][j] = 'x';
		printm(mapcpy);
		if (resolver(mapcpy, map, i, j, counter) == -1)
			return -1;
		else
			return (0);
	}

	
	if(counter != elNum)
		return -1;
	return 0;
}*/
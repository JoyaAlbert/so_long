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
void	deletexs(char **map)
{
	int i;
	int	j;

	i = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j] != '\0')
		{
			if (map[i][j] == 'x')
				map[i][j] = '0';
			j++;
		}
		i++;
	}
}

//revisar patron x1
//				 xx1
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

	
	if(counter != elNum)
		return -1;
	return 0;
}

int	player(char **map, char **mapcpy)
{
	int i;
	int j;
	int	counter;

	printm(mapcpy);
	counter  = 0;
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while  (map[i][j] != '\0')
		{
			if (map[i][j] == 'P')
				return (resolver(mapcpy, map, i, j, counter));
			j++;
		}
		i++;
	}
	return (0);
}

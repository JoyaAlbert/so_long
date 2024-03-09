#include "gnl/get_next_line.h"
#include "printf/ft_printf.h"
#include <stdio.h>

char    **mapchecker(char *map);
int	    matrixtam(char *map_name);
char    **matrix(int width,int length);
char **fillmatrix(char **map, char *map_name, int length);
int     nameformat(char *map);
int		elementCounter(char **map, int length, int width, char element);
int		elementchecker(char **map, int length, int width);
int		solvableCheck(char	**map, int length, int width);
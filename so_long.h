#include "gnl/get_next_line.h"
#include "printf/ft_printf.h"
#include <stdio.h>

char    **mapchecker(char *map);
int	    matrixwidth(char *map_array);
int	matrixlength(char *map_array);
char    **matrix(int width,int length);
char	**fillmatrix(char *map_array, int length, int width, char **map);
int     nameformat(char *map);
int		elementCounter(char **map, int length, int width, char element);
int		elementchecker(char **map, int length, int width);
int		solvableCheck(char	**map, int length, int width);
char	*get_map(char *map_name);
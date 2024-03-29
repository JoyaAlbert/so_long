#include "gnl/get_next_line.h"
#include "printf/ft_printf.h"
#include <stdio.h>

int     nameformat(char *map);
//maps
char    **mapchecker(int length, char *map_array);
int		elementCounter(char **map, int length, int width, char element);
int		elementchecker(char **map, int length, int width);
int		solvableCheck(char	**map, int length, int width);
int     strangechar(char **map, int length);
int	    possibleWay(char **map, int length);
char	*get_map(char *map_name);
//matrix
int	    matrixwidth(char *map_array);
int	    matrixlength(char *map_array);
void    matrix_free(char **map, int length);
char	**ft_split(char *s, char c);
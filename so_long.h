#include "gnl/get_next_line.h"
#include "printf/ft_printf.h"
#include <stdio.h>

int     nameformat(char *map);
//maps
char	**mapchecker(int length, char *map_array, char **mapcpy);
int		elementCounter(char **map, char element);
int		elementchecker(char **map);
int		solvableCheck(char	**map, int length, int width);
int     strangechar(char **map);
int	possibleWay(char **map, char **mapcpy);
char	*get_map(char *map_name);
int elementsTofind(char **map);
int	player(char **map, char **mapcpy);
int	blockedelement(char **map, int i, int j);
//matrix
int	    matrixwidth(char *map_array);
int	    matrixlength(char *map_array);
void    matrix_free(char **map, int length);
char	**ft_split(char *s, char c);

int	resolver(char **mapcpy, char **map, int i, int j, int counter);
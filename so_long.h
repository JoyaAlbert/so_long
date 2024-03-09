#include "gnl/get_next_line.h"
#include "printf/ft_printf.h"
#include <stdio.h>

char    **mapchecker(char *map);
int	    matrixtam(char *map_name);
char    **matrix(int width,int length);
char **fillmatrix(char **map, char *map_name, char *aux);
int     nameformat(char *map);
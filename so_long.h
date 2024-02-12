#include "gnl/get_next_line.h"
#include "printf/ft_printf.h"
#include <stdio.h>

char    **mapchecker(char *map);
int	    matrixtam(int fd);
char    **matrix(int width,int length, char *aux, int fd);
char    **fillmatrix(char **map, int fd);
int     nameformat(char *map);
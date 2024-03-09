#include "so_long.h"

int main(int argc, char *argv[])
{   
    char    *map_name = "test.ber";
	char	**map;

	map = mapchecker(map_name);
	if (map == NULL)
		return (0);
	for (int i = 0; i< 12; i++)
		ft_printf("%s", map[i]);
    
}

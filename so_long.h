#ifndef SO_LONG_H
# define SO_LONG_H

# include "gnl/get_next_line.h"
# include "printf/ft_printf.h"
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>

typedef struct data_list
{
	void	*mlx;
	void	*win;
	char	*map_array;
	char	**map;
	int		l;
	int		w;
	int		p_y;
	int		p_x;
	int		e_y;
	int		e_x;
	int		moves;
	int		mv_u;
	int		mv_d;
	int		mv_r;
	int		mv_l;
	int		fixed_u;
	int		fixed_d;
	int		fixed_r;
	int		fixed_l;
	int		total_col;
	int		col_obt;
	void	*wall;
	void	*col;
	void	*escape;
	void	*escape_p;
	void	*player;
	void	*player_u;
	void	*player_r;
	void	*player_l;
	void	*grnd;
	void	*banner;
}	t_list;

int		nameformat(char *map, int argc);
//maps
char	**mapchecker(int length, char *map_array, char **mapcpy);
int		elementCounter(char **map, char element);
int		elementchecker(char **map);
int		solvableCheck(char	**map, int length, int width);
int		strangechar(char **map);
int		possibleWay(char **map, char **mapcpy);
char	*get_map(char *map_name);
int		elementsTofind(char **map);
int		player(char **map, char **mapcpy);
int		blockedelement(char **map, int i, int j);
//matrix
int		matrixwidth(char *map_array);
int		matrixlength(char *map_array);
void	matrix_free(char **map, int length);
char	**ft_split(char *s, char c);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
//solution
int		resolution(char **mapcpy, char **map, int i, int j);
int		right(int i, int j, int a, char **mapcpy, int counter);
int		left(int i, int j, int a, char **mapcpy, int counter);
int		up(int i, int j, int a, char **mapcpy, int counter);
int		down(int i, int j, int a, char **mapcpy, int counter);
int		lastcheck(int i, int j, int a, char **mapcpy, int counter);
void	printm(char	**a);
//GRAFICOOOOS

void	textureinits(t_list *a);
void	putimgs(t_list *a);

//logicaa
int		inputs(int inputs, t_list *a);
void	ft_frees(t_list *a);
void	e_pos(t_list *a);
void	p_pos(t_list *a);
int	exitcheck(t_list *a);
#endif
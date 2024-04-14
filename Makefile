SRC				=	gnl/get_next_line.c gnl/get_next_line_utils.c printf/ft_printf.c printf/ft_printf_utils.c printf/ft_printf_scdi.c printf/ft_printf_u.c printf/ft_printf_x.c printf/ft_printf_p.c \
					matrix.c maps.c checker_aux.c map_split.c resolution.c resolution_aux.c  inits.c inputs.c inputs_aux.c so_long.c
GCC 			=	gcc
CFLAGS			=	-Wall -Wextra -Werror
OBJ				=	$(SRC:.c=.o)
MLX				=	mlx/libmlx.a
NAME			=	so_long

CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m

$(NAME):		$(OBJ)
				@clear
				@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CYAN}"
				$(GCC) $(OBJ) $(MLX) $(FLAGS)  -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) 


all:			$(NAME)

RM				=	rm -f

pato:			
				@clear 
				@echo "${YELLOW}'⣿⣿⣿⣿⣿⣿⣿⣿⡿⢋⣩⣭⣶⣶⣮⣭⡙⠿⣿⣿⣿⣿⣿⣿'\n'⣿⣿⣿⣿⣿⣿⠿⣋⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⡙⢿⣿⣿⣿'\n'⣿⣿⣿⣿⣿⡃⠄⠹⡿⣿⣿⣿⣿⠟⠛⣿⣿⣿⣿⣷⡌⢿⣿⣿'\n'⣿⣿⣿⣿⣿⠐⣠⡶⣶⣲⡎⢻⣿⣤⣴⣾⣿⣿⣿⣿⣿⠸⣿⣿'\n'⣿⠟⣋⡥⡶⣞⡯⣟⣾⣺⢽⡧⣥⣭⣉⢻⣿⣿⣿⣿⣿⣆⢻⣿"
				@echo "${YELLOW}'⡃⣾⢯⢿⢽⣫⡯⣷⣳⢯⡯⠯⠷⠻⠞⣼⣿⣿⣿⣿⣿⣿⡌⣿'\n'⣦⣍⡙⠫⠛⠕⣋⡓⠭⣡⢶⠗⣡⣶⡝⣿⣿⣿⣿⣿⣿⣿⣧⢹'\n'⣿⣿⣿⣿⣿⣿⣘⣛⣋⣡⣵⣾⣿⣿⣿⢸⣿⣿⣿⣿⣿⣿⣿⢸'\n'⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢸⣿⣿⣿⣿⣿⣿⣿⢸'\n'⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢸⣿⣿⣿⣿⣿⣿⣿⢸'\n'⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢸⣿⣿⣿⣿⣿⣿⣿⢸'\n'"


clean:			
				@echo "$(RED)Deleting ${YELLOW}.o ${CLR_RMV}"
				$(RM) $(OBJ)

fclean:			pato clean 
				@echo "$(RED)Deleting ${YELLOW}.a ${CLR_RMV}"
				$(RM) $(NAME) 
				


re:				fclean all

.PHONY: all clean fclean re
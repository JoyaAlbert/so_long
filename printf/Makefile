# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajoya-pi <ajoya-pi@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/16 13:21:42 by ajoya-pi          #+#    #+#              #
#    Updated: 2023/10/23 13:26:26 by ajoya-pi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC				=	ft_printf.c ft_printf_utils.c ft_printf_scdi.c ft_printf_u.c ft_printf_x.c ft_printf_p.c

OBJ				=	$(SRC:.c=.o)
LIB				=	ar rcs
CFLAGS			=	-Wall -Wextra -Werror
NAME			=	libftprintf.a

$(NAME):		$(OBJ)
				$(LIB) $(FLAGS) $(NAME) $(OBJ)

all:			$(NAME)

RM				=	rm -f
clean:
				$(RM) $(OBJ)
fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY: all clean fclean re

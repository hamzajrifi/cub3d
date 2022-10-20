CC = gcc 

NAME = cub

C_FLAG = -Wall -Wextra -Werror 

FLAG_MLX =  -lmlx -framework OpenGL -framework AppKit

C_FILES =	./get_next_line/get_next_line_utils.c \
			./get_next_line/get_next_line.c \
			./utils/utils_functions.c \
			./checker/read_map.c \
			./ft_error/ft_error.c

HDR  =	cub3d.h

all : $(NAME)
$(NAME) : $(NAME) $(HDR)
		$(CC) -o $(NAME) main.c $(C_FILES)

clean : 
	rm -f *.o ./checker/*.o ./get_next_line/*.o ./utils/*.o

fclean :
	rm -f cub

re : fclean all
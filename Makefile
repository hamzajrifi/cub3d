CC = gcc 

NAME = cub

C_FLAG = -Wall -Wextra -Werror 

FLAG_MLX = -lmlx -framework OpenGL -framework AppKit

C_FILES =	./get_next_line/get_next_line_utils.c \
			./get_next_line/get_next_line.c \
			./utils/utils_functions.c \
			./checker/read_map.c 

HDR  =	cub3d.h

all : $(NAME)
$(NAME) : $(NAME) $(HDR)
		$(CC) $(C_FLAG) $(FLAG_MLX) -o $(NAME) main.c $(C_FILES)
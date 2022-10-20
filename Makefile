CC = gcc 

NAME = cub

C_FLAG = -Wall -Wextra -Werror 

FLAG_MLX =  -lmlx -framework OpenGL -framework AppKit

C_FILES =	./get_next_line/get_next_line_utils.c \
			./get_next_line/get_next_line.c \
			./utils/utils_functions.c \
			./utils/ft_split.c \
			./utils/ft_libft_substr.c \
			./utils/ft_strtrim.c \
			./ft_error/ft_error.c \
			./checker/read_map.c \
			./checker/check_color.c

HDR  =	cub3d.h

all : $(NAME)
$(NAME) : $(HDR)
		$(CC) -o $(NAME) main.c $(C_FILES)

clean : 
	rm -f *.o ./checker/*.o ./get_next_line/*.o ./utils/*.o

fclean :
	rm -f cub

re : fclean all
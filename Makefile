INC=%%%%

INCLIB=$(INC)/../lib

CC = gcc 

NAME = cub3D

C_FLAG = -Wall -Wextra -Werror 

FLAG_MLX_MAC =  -lmlx -framework OpenGL -Ofast -framework AppKit

C_FILES =	utils/get.c \
			utils/ft_split.c \
			utils/ft_atoi.c \
			utils/ft_strtrim.c \
			utils/ft_substr.c  \
			utils/libft_utils.c  \
			utils/ft_strjoin.c  \
			parse/check_map.c \
			parse/check_characters.c \
			parse/check_range.c \
			parse/check_file.c \
			parse/parse_backslash.c \
			parse/parse_line.c \
			parse/utils_check_file.c \
			hooks/hooks.c \
			initial_param/initial_param.c\
			raycasting/rander_map.c \
			raycasting/drawing.c \
			raycasting/print_in_win.c\
			raycasting/distance.c \
			raycasting/texture.c \
			raycasting/minimap.c\
			raycasting/map_2d.c

HDR  =	cub.h

all : $(NAME)
$(NAME) : $(HDR) $(C_FILES) cub.c
	$(CC) -o $(NAME)  cub.c $(C_FILES) $(C_FLAG) $(FLAG_MLX_MAC)
		

clean : 
	rm -f cub3D

fclean : clean

re : fclean all
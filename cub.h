/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 00:06:23 by hjrifi            #+#    #+#             */
/*   Updated: 2022/11/19 00:23:03 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include <math.h>
# include <mlx.h>
// #include "../mlx.h"
// #include "../mlx_int.h"
# define PI 3.14159265359
# define TWO_PI 6.28318530
# define TILE_SIZE 64
# define WIN_WIDTH 1200
# define WIN_HEIGHT 900

typedef struct s_path {
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	char	*floor_color;
	char	*ceilling_color;
	int		color_of_f[3];
	int		color_of_c[3];
	int		color_f;
	int		color_c;
	int		pos_x_player;
	int		pos_y_player;
	char	**map;
	int		map_y;
	int		map_x;
	int		check;
	int		tab[6];
	char	pdirec;
	int		parse;
}	t_path;

typedef struct s_check_map {
	int		i;
	int		j;
	int		size;
	char	*tab1;
	char	**tab;
	char	*str;
	int		i_i;
}	t_check_map;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_win {
	void	*mlx;
	void	*mlx_win;
}	t_win;

typedef struct s_rays {
	float	x1;
	float	y1;
	int		dx;
	int		dy;
	int		steps;
	float	xinc;
	float	yinc;
	float	x_p;
	float	y_p;
	float	h_x;
	float	h_y;
	float	v_x;
	float	v_y;
	float	ang;
	int		found_h;
	int		found_v;
	float	distance;
}	t_rays;

typedef struct s_player {
	float	x;
	float	y;
	float	width;
	float	height;
	int		turn_d;
	int		walk_d;
	int		walk_lr;
	float	rotation_angle;
	float	walkspeed;
	float	turnspeed;
}	t_player;

typedef struct s_texture {
	void	*img;
	void	*add;
	int		width;
	int		height;
	int		sizeline;
	int		endian;
	int		pixle_b;
}	t_texture;

typedef struct s_wall
{
	float	wall_he;
	float	top_y;
	float	btm_y;
	float	dg;
}	t_wall;

typedef struct s_allData {
	t_win		i_win;
	t_data		data;
	t_player	player;
	t_path		*path;
	t_rays		rays;
	t_texture	txtr_n;
	t_texture	txtr_s;
	t_texture	txtr_e;
	t_texture	txtr_w;
	t_data		m_map;
	float		ray_angle;
	int			x_mouse;
}	t_allData;

typedef struct s_cher {
	int	n_txtr;
	int	s_txtr;
	int	w_txtr;
	int	e_txtr;
}	t_cher;

int		size_map(int fd);
void	check_range(char *line, t_path *path);
void	check_characters(t_path *path);
void	check_map_it_is_valid(char *str, t_path *path);
char	*ft_strrchr(char *str, int c);
char	*ft_strchr(char *str, int c);
char	*ft_strstr(char *str, char *to_find, int size);
char	*ft_strstr2(char *str, char *to_find, int size);
char	*get_next_line(int fd);
int		ft_atoi(const char *str);
size_t	ft_strlen(char *str);
char	*ft_strdup(char *str);
char	**ft_split(char *s, char l);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);

//// hooks.c
void	open_win(t_allData *all);

////// initial_param.c /////
void	initial_param(t_path *path, t_allData *all);
void	inital_player(t_allData *all, t_path *path);
void	initial_win(t_allData *all);
void	initial_win_data(t_allData *all);

////// check_file.c
////// check_file.c
void	get_no(char *str, t_path *path);
void	get_so(char *str, t_path *path);
void	get_we(char *str, t_path *path);
void	get_ea(char *str, t_path *path);
void	get_f(char *str, t_path *path);
int		len(char *str, int c);
void	add_valid_path(t_path *path, int i, char *str);
char	*get_str(char *string, int size);
bool	check_name_of_file(char *str);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		check_position(t_path *path, int i, int j);
void	check_walls(t_path *path);
void	check_duplicate(t_path *path);
void	check_backslash(t_check_map *check, t_path *path, int j);
void	check_path_xpm(t_path *path);
void	last_line(t_path *path, int i);
void	first_line(t_path *path);
int		calcul_x_map(char **map);
void	get_path(int fd, t_path *path);
int		add_all_path_of_texture(char *line, t_path *path, int i, char *str);
void	get_c(char *str, t_path *path);
int		check_path_of_texture(t_path *path, char *line, int a);
int		utiils_check_walls(t_path *path, int i, int j);

//// raycasting/rander_map.c
void	raycasting(t_allData *all);
void	update_player(t_allData *all);

/// raycasting/drawing.c
void	check_rays(t_allData *all);

/// print_in_win.c
void	print_dda_lines(t_allData *all_data);
void	put_wall(t_allData *all, int x);

/// distance.c
void	check_distance_to_wall(t_allData *all);
int		calcul_steps(int dx, int dy);
int		check_if_has_wall(t_allData *all, float x, float y);

//// minimap.c
void	mini_map(t_allData *all);

#endif

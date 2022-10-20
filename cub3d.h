#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
// # include <mlx.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct n_north
{
    char *NO;
    char *SO;
    char *WE;
    char *EA;
}t_north;


typedef struct n_data
{
    char    **map;
    char    *path_map;
    int     fd;
    t_north north;
    int     *F;
    int     *C;
}t_data;

//============ get_next_line =============== 
char    *get_next_line(int fd);
void	free_mytab(char	**str);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
long	ft_strlen(const char *str);
char	*ft_strdup(char *s1);
char	*ft_strchr(char *s, int c);
char	*ft_substr(char *s, int start, int len);
char	*ft_strjoin(char *s1, char *s2);

//============ checker/read_map ===============
int     read_map(t_data *data);
int     get_nbr_color(t_data *data,char *str);

//============ utils/
    //
    // -->>  1 ---- utils_functions.c ===============
int     calc_line(char **map);
int     ft_atoi(const char *str);
    // -->>  2 ---- ft_split.c ===============
char	*ft_libft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
    // -->>  3 ---- ft_strtim.c ===============
char	*ft_strtrim(char const *s1, char const *set);

//============ ft_error/ft_error.c ===============
int     ft_error(char *str);

# endif
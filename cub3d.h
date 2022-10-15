#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct n_data
{
    char **map;
    char *path_img;
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

//============ utils/utils_functions ===============
int     calc_line(char **map);

# endif
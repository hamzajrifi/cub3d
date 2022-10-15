#include "../cub3d.h"

int read_map(t_data *data)
{
    int fd;

    fd = open(data->path_img, O_RDWR, 0677);
    
    get_next_line(fd);
    return (0);
}
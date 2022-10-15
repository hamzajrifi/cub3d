#include "cub3d.h"

int main(int ac, char **av)
{
    t_data data;

    if (av[1])
        data.path_img = av[1];
    if (ac != 2 && read_map(&data))
    {
        printf("please insert 2 argiment \n");
        return (1);
    }
    return (0);
}
#include "cub3d.h"

int main(int ac, char **av)
{
    t_data data;

    if (ac == 2)
        data.path_map = av[1];
    if (ac != 2 || read_map(&data))
        return (1);
    printf("end programe\n");
    return (0);
}
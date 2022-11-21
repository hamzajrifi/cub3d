#include "../cub.h"

static void rec_2d(t_data *data, int x, int y, int color)
{
	int i = -1;
	int j;
	int a;
	int b = y;

	while (++i < TILE_SIZE - 1)
	{
        j = -1;
        a = x;
		while (++j < TILE_SIZE - 1)
		{
			my_mlx_pixel_put(data, a, b, color);
			a++;
		}
			my_mlx_pixel_put(data, a, b, 0x9E9E9E9E);
		b++;
	}
	while (j < TILE_SIZE)
	{
		my_mlx_pixel_put(data, a, b, 0x9E9E9E9E);
		a++;
		j++;
	}
}

void    mini_map_2d(t_allData *all)
{
	int x = 0;
    int y = 0;
	
	while (all->path->map[y])
	{
		x = 0;
		while (all->path->map[y][x])
		{
			if (all->path->map[y][x] == '1')
				rec_2d(&all->data, x * TILE_SIZE, y * TILE_SIZE, 0xFFFFFF);
			else if (all->path->map[y][x] == '0')
				rec_2d(&all->data, x * TILE_SIZE, y * TILE_SIZE, 0xFFE0B2);
			x++;
		}
		y++;
	}
}
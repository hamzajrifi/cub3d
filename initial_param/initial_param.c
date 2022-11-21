/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_param.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 00:37:20 by hjrifi            #+#    #+#             */
/*   Updated: 2022/11/21 01:59:53 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	initial_add_img(t_allData *all)
{
	all->data.addr = mlx_get_data_addr(all->data.img, &all->data.bits_per_pixel,
			&all->data.line_length, &all->data.endian);
	all->m_map.addr = mlx_get_data_addr(all->m_map.img,
			&all->m_map.bits_per_pixel, &all->m_map.line_length,
			&all->m_map.endian);
	all->txtr_n.add = mlx_get_data_addr(all->txtr_n.img, &all->txtr_n.pixle_b,
			&all->txtr_n.sizeline, &all->txtr_n.endian);
	all->txtr_s.add = mlx_get_data_addr(all->txtr_s.img, &all->txtr_s.pixle_b,
			&all->txtr_s.sizeline, &all->txtr_s.endian);
	all->txtr_e.add = mlx_get_data_addr(all->txtr_e.img, &all->txtr_e.pixle_b,
			&all->txtr_e.sizeline, &all->txtr_e.endian);
	all->txtr_w.add = mlx_get_data_addr(all->txtr_w.img, &all->txtr_w.pixle_b,
			&all->txtr_w.sizeline, &all->txtr_w.endian);
}

void	initial_win_data(t_allData *all)
{
	all->data.img = mlx_new_image(all->i_win.mlx, WIN_WIDTH, WIN_HEIGHT);
	all->m_map.img = mlx_new_image(all->i_win.mlx, 161, 161);
	all->txtr_n.img = mlx_xpm_file_to_image(all->i_win.mlx,
			all->path->north_texture, &all->txtr_n.width,
			&all->txtr_n.height);
	all->txtr_s.img = mlx_xpm_file_to_image(all->i_win.mlx,
			all->path->south_texture, &all->txtr_s.width,
			&all->txtr_s.height);
	all->txtr_e.img = mlx_xpm_file_to_image(all->i_win.mlx,
			all->path->east_texture, &all->txtr_e.width,
			&all->txtr_e.height);
	all->txtr_w.img = mlx_xpm_file_to_image(all->i_win.mlx,
			all->path->west_texture, &all->txtr_w.width,
			&all->txtr_w.height);
	if (!all->txtr_n.img || !all->txtr_s.img || !all->txtr_e.img
		|| !all->txtr_w.img || !all->m_map.img || !all->data.img)
	{
		printf("Error\n");
		exit(0);
	}
	initial_add_img(all);
}

float	check_player_direction(char c)
{
	if (c == 'W')
		return (PI);
	else if (c == 'S')
		return (PI / 2);
	else if (c == 'N')
		return (3 * PI / 2);
	else if (c == 'E')
		return (0);
	return (0);
}

void	initial_player(t_allData *all, t_path *path)
{
	all->path = path;
	all->player.x = path->pos_y_player * TILE_SIZE + (TILE_SIZE / 2);
	all->player.y = path->pos_x_player * TILE_SIZE + (TILE_SIZE / 2);
	all->player.width = 1;
	all->player.height = 1;
	all->player.turn_d = 0;
	all->player.walk_d = 0;
	all->player.rotation_angle = check_player_direction(path->pdirec);
	all->ray_angle = all->player.rotation_angle - (PI / 6);
	all->player.walkspeed = 3;
	all->player.turnspeed = 3 * (PI / 180);
}

void	initial_param(t_path *path, t_allData *all)
{
	initial_player(all, path);
	all->path->color_c = all->path->color_of_c[2] + (all->path->color_of_c[1]
			* 256) + (all->path->color_of_c[0] * 256 * 256);
	all->path->color_f = all->path->color_of_f[2] + (all->path->color_of_f[1]
			* 256) + (all->path->color_of_f[0] * 256 * 256);
	all->i_win.mlx = mlx_init();
	all->i_win.mlx_win = mlx_new_window(all->i_win.mlx, WIN_WIDTH,
			WIN_HEIGHT, "Hjrifi CUB3D");
	all->data.img = mlx_new_image(all->i_win.mlx, WIN_WIDTH, WIN_HEIGHT);
	all->data.addr = mlx_get_data_addr(all->data.img,
			&all->data.bits_per_pixel, &all->data.line_length,
			&all->data.endian);
}

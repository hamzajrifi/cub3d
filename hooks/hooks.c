/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:28:34 by hjrifi            #+#    #+#             */
/*   Updated: 2022/11/19 00:24:43 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	move_player(int keycode, t_allData *all)
{
	if (keycode == 124 || keycode == 65363)
		all->player.turn_d = 1;
	if (keycode == 123 || keycode == 65361)
		all->player.turn_d = -1;
	if (keycode == 65362 || keycode == 13)
		all->player.walk_d = 1;
	if (keycode == 2)
		all->player.walk_lr = 1;
	if (keycode == 0)
		all->player.walk_lr = -1;
	if (keycode == 65364 || keycode == 1)
		all->player.walk_d = -1;
	if (all->player.walk_d || all->player.turn_d || all->player.walk_lr)
	{
		update_player(all);
		raycasting(all);
		all->player.walk_d = 0;
		all->player.turn_d = 0;
		all->player.walk_lr = 0;
	}
	if (keycode == 65307 || keycode == 53)
		exit (0);
	return (0);
}

int	ft_bye(char *str)
{
	(void) str;
	exit(0);
	return (0);
}

int	ft_move_mouse(int x, int y, t_allData *all)
{
	(void)y;
	if (x < (WIN_WIDTH / 2) - 15 && x >= 0)
		all->player.turn_d = -1;
	else if (x > (WIN_WIDTH / 2) + 15 && x <= WIN_WIDTH)
		all->player.turn_d = 1;
	if (all->player.walk_d || all->player.turn_d)
	{
		update_player(all);
		raycasting(all);
		all->player.walk_d = 0;
		all->player.turn_d = 0;
	}
	return (0);
}

void	open_win(t_allData *all)
{
	mlx_hook(all->i_win.mlx_win, 2, 0, move_player, all);
	mlx_hook(all->i_win.mlx_win, 17, 0, ft_bye, "bye\n");
	mlx_hook(all->i_win.mlx_win, 6, 0, ft_move_mouse, all);
	mlx_loop(all->i_win.mlx);
}

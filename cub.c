/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjrifi <hjrifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 00:06:10 by hjrifi            #+#    #+#             */
/*   Updated: 2022/11/18 18:32:49 by hjrifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(int ac, char **av)
{
	t_path		path;
	t_allData	all;

	if (ac > 2 || ac < 2)
	{
		write(2, "<exec> <File.cub>\n", 17);
		return (0);
	}
	check_name_of_file(av[1]);
	check_map_it_is_valid(av[1], &path);
	initial_param(&path, &all);
	raycasting(&all);
	open_win(&all);
	return (0);
}

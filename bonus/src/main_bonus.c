/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 20:34:33 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/13 14:49:11 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	main(int argc, char **argv)
{
	t_map			map;
	t_transform		transform;
	t_mlx			mlx;
	t_mode			mode;

	check_argument(argc, argv);
	ft_bzero(&map, sizeof(t_map));
	ft_bzero(&transform, sizeof(t_transform));
	ft_bzero(&mlx, sizeof(t_mlx));
	ft_bzero(&mode, sizeof(t_mode));
	create_map(&map, argv[1]);
	init_transform(&map, &transform, &mode);
	ft_init_mlx(&map, &mlx);
	init_modes(&map, &transform, &mode);
	ft_mlx_hooks(&map, &transform, &mlx, &mode);
	clear_map(&map);
	ft_mlx_destroy(&mlx);
	return (0);
}

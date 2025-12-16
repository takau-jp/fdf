/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 20:34:33 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/14 13:19:22 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map			map;
	t_transform		transform;
	t_mlx			mlx;

	check_argument(argc, argv);
	ft_bzero(&map, sizeof(t_map));
	ft_bzero(&transform, sizeof(t_transform));
	ft_bzero(&mlx, sizeof(t_mlx));
	create_map(&map, argv[1]);
	init_transform(&map, &transform);
	ft_init_mlx(&map, &mlx);
	transformation(&map, &transform);
	orthographic_projection(&map);
	draw_wireframe(&map, &mlx);
	ft_mlx_hooks(&mlx);
	clear_map(&map);
	ft_mlx_destroy(&mlx);
	return (0);
}

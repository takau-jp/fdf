/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_error_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 00:02:44 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/13 14:13:10 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	ft_mlx_error_handler(\
			t_map *map, t_mlx *mlx, void (*ft_error_func)(void))
{
	if (map != NULL)
		clear_map(map);
	if (mlx != NULL)
		ft_mlx_destroy(mlx);
	ft_error_func();
}

void	ft_mlx_create_connection_error(void)
{
	ft_dprintf(STDERR_FILENO, "Error\n");
	ft_dprintf(STDERR_FILENO, \
		"\033[1;31mFailed to create mlx connection.\033[0m\n");
	exit(1);
}

void	ft_mlx_create_window_error(void)
{
	ft_dprintf(STDERR_FILENO, "Error\n");
	ft_dprintf(STDERR_FILENO, \
		"\033[1;31mFailed to create window.\033[0m\n");
	exit(1);
}

void	ft_mlx_create_image_error(void)
{
	ft_dprintf(STDERR_FILENO, "Error\n");
	ft_dprintf(STDERR_FILENO, \
		"\033[1;31mFailed to create image.\033[0m\n");
	exit(1);
}

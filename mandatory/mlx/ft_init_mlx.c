/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:07:48 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/13 14:24:32 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

bool	ft_mlx_create_connection(t_mlx *mlx);
bool	ft_mlx_create_window(t_mlx *mlx);

void	ft_init_mlx(t_map *map, t_mlx *mlx)
{
	if (!ft_mlx_create_connection(mlx))
		ft_mlx_error_handler(map, mlx, ft_mlx_create_connection_error);
	if (!ft_mlx_create_window(mlx))
		ft_mlx_error_handler(map, mlx, ft_mlx_create_window_error);
	if (!ft_mlx_init_model_image(mlx))
	{
		if (mlx->model_img.z_buffer == NULL)
		{
			clear_map(map);
			ft_mlx_destroy(mlx);
			errno_error("malloc");
		}
		ft_mlx_error_handler(map, mlx, ft_mlx_create_image_error);
	}
}

bool	ft_mlx_create_connection(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
		return (false);
	return (true);
}

bool	ft_mlx_create_window(t_mlx *mlx)
{
	mlx->width = W_WIDTH;
	mlx->height = W_HEIGHT;
	mlx->win_ptr = mlx_new_window(
			mlx->mlx_ptr, mlx->width, mlx->height, "fdf");
	if (mlx->win_ptr == NULL)
		return (false);
	return (true);
}

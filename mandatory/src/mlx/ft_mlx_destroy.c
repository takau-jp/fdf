/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 01:02:29 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/13 14:24:32 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_mlx_destroy(t_mlx *mlx)
{
	if (mlx->model_img.z_buffer != NULL)
		clear_z_buffer(&(mlx->model_img));
	if (mlx->model_img.img_ptr != NULL)
		mlx_destroy_image(mlx->mlx_ptr, mlx->model_img.img_ptr);
	if (mlx->win_ptr != NULL)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	if (mlx->mlx_ptr != NULL)
	{
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
	}
}

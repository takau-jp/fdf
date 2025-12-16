/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 22:28:29 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/13 14:12:42 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	draw_pixel(t_mlx *mlx, t_screen pixel)
{
	if (!(0 <= pixel.x && pixel.x < W_WIDTH) \
		|| !(0 <= pixel.y && pixel.y < W_HEIGHT))
		return ;
	if (mlx->model_img.z_buffer[pixel.y][pixel.x] < pixel.z_depth)
		return ;
	*(ft_mlx_get_pixel_addr(mlx->model_img, pixel.x, pixel.y)) \
		= mlx_get_color_value(mlx->mlx_ptr, pixel.color.rgb);
	mlx->model_img.z_buffer[pixel.y][pixel.x] = pixel.z_depth;
}

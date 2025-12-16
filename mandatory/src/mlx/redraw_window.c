/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:07:22 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/13 15:24:00 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	redraw_window(t_mlx	*mlx)
{
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_put_image_to_window(\
		mlx->mlx_ptr, mlx->win_ptr, mlx->model_img.img_ptr, 0, 0);
}

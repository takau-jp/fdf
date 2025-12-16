/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw_window_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:07:22 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/13 14:43:17 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	redraw_window(t_ctx *ctx)
{
	t_mlx	*mlx;

	mlx = ctx->mlx;
	draw_wireframe(ctx);
	if (ctx->mode->control_panel_visible == true)
		draw_control_panel(mlx, ctx->mode);
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_put_image_to_window(\
		mlx->mlx_ptr, mlx->win_ptr, mlx->model_img.img_ptr, 0, 0);
	if (ctx->mode->control_panel_visible == true)
		draw_status(ctx);
	if (!ft_mlx_reset_model_image(mlx))
		ft_mlx_error_handler(ctx->map, mlx, ft_mlx_create_image_error);
}

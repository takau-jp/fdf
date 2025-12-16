/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_control_panel_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 23:05:50 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/14 12:33:38 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	draw_control_panel(t_mlx *mlx, t_mode *mode)
{
	unsigned int	*pixel_addr;
	unsigned int	pixel_color;
	int				x;
	int				y;
	int				cp_height;

	cp_height = CP_PARALLEL_HEIGHT;
	if (mode->projection == PERSPECTIVE)
		cp_height = CP_PERSPECTIVE_HEIGHT;
	else if (mode->projection == FPS)
		cp_height = CP_FPS_HEIGHT;
	y = CP_WINDOW_OFFSET;
	while (y < cp_height + CP_WINDOW_OFFSET)
	{
		x = CP_WINDOW_OFFSET;
		while (x < CP_WIDTH + CP_WINDOW_OFFSET)
		{
			pixel_addr = ft_mlx_get_pixel_addr(mlx->model_img, x, y);
			pixel_color = *pixel_addr;
			*pixel_addr = source_over_alpha_blend(\
							pixel_color, 1.0, CP_COLOR, CP_ALPHA);
			x++;
		}
		y++;
	}
}

void	draw_status(t_ctx *ctx)
{
	const int	x_offset = CP_WINDOW_OFFSET + 10;
	int			y_offset;

	y_offset = CP_WINDOW_OFFSET + MSG_LINE_HEIGHT;
	draw_control_panel_msg(ctx, x_offset, &y_offset);
	draw_projection_mode_msg(ctx, x_offset, &y_offset);
	draw_color_mode_msg(ctx, x_offset, &y_offset);
	draw_lens_mode_msg(ctx, x_offset, &y_offset);
	draw_scale_mode_msg(ctx, x_offset, &y_offset);
	draw_translation_mode_msg(ctx, x_offset, &y_offset);
	draw_rotation_mode_msg(ctx, x_offset, &y_offset);
	draw_screen_translation_msg(ctx, x_offset, &y_offset);
	draw_fps_mode_msg(ctx, x_offset, &y_offset);
}

void	draw_msg(t_mlx *mlx, int x, int *y, char *msg)
{
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, x, *y, MSG_COLOR, msg);
	*y += MSG_LINE_HEIGHT;
}

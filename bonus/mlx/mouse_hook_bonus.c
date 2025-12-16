/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 16:44:02 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/13 14:14:48 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	button_press_hook(unsigned int button, int x, int y, t_ctx *ctx)
{
	if (button == Button1 || button == Button2)
	{
		ctx->mlx->mouse.x = x;
		ctx->mlx->mouse.y = y;
	}
	else if (button == Button4 || button == Button5)
	{
		if (ctx->mode->scale == MODEL_SCALE \
			&& change_model_scale(button, ctx->transform))
			;
		else if (ctx->mode->scale == ZOOM_SCALE \
			&& change_zoom_scale(button, ctx->transform, ctx->mode))
			;
		else
			return (0);
		transform(ctx->map, ctx->transform, ctx->mode);
		redraw_window(ctx);
	}
	return (0);
}

int	button1_motion_hook(int x, int y, t_ctx *ctx)
{
	if (ctx->mode->projection == FPS)
	{
		if (!change_player_angle(x, y, ctx))
			return (0);
	}
	else if (ctx->mode->rotation == NORMAL_ROTATION)
	{
		if (!change_normal_rotation(x, y, ctx))
			return (0);
	}
	else if (ctx->mode->rotation == MODEL_ROTATION)
	{
		if (!change_model_rotation(x, y, ctx))
			return (0);
	}
	else if (ctx->mode->rotation == VIEW_ROTATION)
	{
		if (!change_view_rotation(x, y, ctx))
			return (0);
	}
	transform(ctx->map, ctx->transform, ctx->mode);
	redraw_window(ctx);
	return (0);
}

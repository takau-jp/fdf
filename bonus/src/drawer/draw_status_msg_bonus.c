/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_status_msg_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 02:18:37 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/13 14:12:46 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	draw_control_panel_msg(t_ctx *ctx, int x, int *y)
{
	ft_sprintf(ctx->mode->msg, "%s", MSG_CONTROL_PANEL);
	draw_msg(ctx->mlx, x, y, ctx->mode->msg);
	ft_sprintf(ctx->mode->msg, "%s", MSG_RESET);
	draw_msg(ctx->mlx, x, y, ctx->mode->msg);
}

void	draw_projection_mode_msg(t_ctx *ctx, int x, int *y)
{
	if (ctx->mode->projection == PARALLEL)
		ft_sprintf(ctx->mode->msg, "%s %s", MSG_PROJECTION_MODE, "Parallel");
	else if (ctx->mode->projection == PERSPECTIVE)
		ft_sprintf(ctx->mode->msg, "%s %s", MSG_PROJECTION_MODE, "Perspective");
	else if (ctx->mode->projection == FPS)
		ft_sprintf(ctx->mode->msg, "%s %s", MSG_PROJECTION_MODE, "FPS");
	draw_msg(ctx->mlx, x, y, ctx->mode->msg);
}

void	draw_color_mode_msg(t_ctx *ctx, int x, int *y)
{
	if (ctx->mode->color == DEFAULT)
		ft_sprintf(ctx->mode->msg, "%s %s", MSG_COLOR_MODE, "Default");
	else if (ctx->mode->color == SET_1)
		ft_sprintf(ctx->mode->msg, "%s %s", MSG_COLOR_MODE, "Set 1");
	else if (ctx->mode->color == SET_2)
		ft_sprintf(ctx->mode->msg, "%s %s", MSG_COLOR_MODE, "Set 2");
	else if (ctx->mode->color == SET_3)
		ft_sprintf(ctx->mode->msg, "%s %s", MSG_COLOR_MODE, "Set 3");
	else if (ctx->mode->color == GEOMETRIC)
		ft_sprintf(ctx->mode->msg, "%s %s", MSG_COLOR_MODE, "Geometric");
	draw_msg(ctx->mlx, x, y, ctx->mode->msg);
}

void	draw_lens_mode_msg(t_ctx *ctx, int x, int *y)
{
	if (ctx->mode->projection == PARALLEL)
		return ;
	if (ctx->mode->lens == STANDARD)
		ft_sprintf(ctx->mode->msg, "%s %s", MSG_LENS_MODE, "Standard");
	else if (ctx->mode->lens == WIDE)
		ft_sprintf(ctx->mode->msg, "%s %s", MSG_LENS_MODE, "Wide");
	else if (ctx->mode->lens == SUPER_WIDE)
		ft_sprintf(ctx->mode->msg, "%s %s", MSG_LENS_MODE, "Super Wide");
	else if (ctx->mode->lens == TELEPHOTO)
		ft_sprintf(ctx->mode->msg, "%s %s", MSG_LENS_MODE, "Telephoto");
	else if (ctx->mode->lens == SUPER_TELEPHOTO)
		ft_sprintf(ctx->mode->msg, "%s %s", MSG_LENS_MODE, "Super Telephoto");
	draw_msg(ctx->mlx, x, y, ctx->mode->msg);
}

void	draw_scale_mode_msg(t_ctx *ctx, int x, int *y)
{
	if (ctx->mode->scale == ZOOM_SCALE)
		ft_sprintf(ctx->mode->msg, "%s %s", MSG_SCALE_MODE, "Zoom Scale");
	else if (ctx->mode->scale == MODEL_SCALE)
		ft_sprintf(ctx->mode->msg, "%s %s", MSG_SCALE_MODE, "Model Scale");
	draw_msg(ctx->mlx, x, y, ctx->mode->msg);
	ft_sprintf(ctx->mode->msg, "%s", MSG_SCALE_CONTROL);
	draw_msg(ctx->mlx, x, y, ctx->mode->msg);
	if (ctx->mode->projection != PARALLEL)
	{
		ft_sprintf(ctx->mode->msg, \
			"%s %.3f", MSG_ZOOM_SCALE, ctx->transform->zoom_scale);
		draw_msg(ctx->mlx, x, y, ctx->mode->msg);
	}
	if (ctx->mode->projection != FPS)
	{
		ft_sprintf(ctx->mode->msg, \
			"%s %.3f", MSG_MODEL_SCALE, ctx->transform->model_scale);
		draw_msg(ctx->mlx, x, y, ctx->mode->msg);
	}
}

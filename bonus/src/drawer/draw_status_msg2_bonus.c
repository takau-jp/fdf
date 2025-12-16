/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_status_msg2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 23:15:29 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/14 13:48:42 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	draw_translation_mode_msg(t_ctx *ctx, int x, int *y)
{
	if (ctx->mode->projection == FPS)
		return ;
	if (ctx->mode->translation == MODEL_TRANSLATION)
		ft_sprintf(ctx->mode->msg, "%s %s", MSG_TRANSLATION_MODE, "Model");
	if (ctx->mode->translation == VIEW_TRANSLATION)
		ft_sprintf(ctx->mode->msg, "%s %s", MSG_TRANSLATION_MODE, "View");
	draw_msg(ctx->mlx, x, y, ctx->mode->msg);
	ft_sprintf(ctx->mode->msg, "%s", MSG_TRANSLATION_CONTROL);
	draw_msg(ctx->mlx, x, y, ctx->mode->msg);
	ft_sprintf(ctx->mode->msg, "%s %.0f / %.0f / %.0f",
		MSG_MODEL_TRANSLATION,
		ctx->transform->model_translation.x,
		ctx->transform->model_translation.y,
		ctx->transform->model_translation.z);
	draw_msg(ctx->mlx, x, y, ctx->mode->msg);
	ft_sprintf(ctx->mode->msg, "%s %.0f / %.0f / %.0f",
		MSG_VIEW_TRANSLATION,
		ctx->transform->view_translation.x,
		ctx->transform->view_translation.y,
		ctx->transform->view_translation.z);
	draw_msg(ctx->mlx, x, y, ctx->mode->msg);
}

void	draw_rotation_mode_msg(t_ctx *ctx, int x, int *y)
{
	if (ctx->mode->projection == FPS)
		return ;
	if (ctx->mode->rotation == NORMAL_ROTATION)
		ft_sprintf(ctx->mode->msg, \
			"%s %s", MSG_ROTATION_MODE, "Normal (Model Y & View X)");
	else if (ctx->mode->rotation == MODEL_ROTATION)
		ft_sprintf(ctx->mode->msg, \
			"%s %s", MSG_ROTATION_MODE, "Model (Model Z & X)");
	else if (ctx->mode->rotation == VIEW_ROTATION)
		ft_sprintf(ctx->mode->msg, \
			"%s %s", MSG_ROTATION_MODE, "View (View Y & Z)");
	draw_msg(ctx->mlx, x, y, ctx->mode->msg);
	ft_sprintf(ctx->mode->msg, "%s", MSG_ROTATION_CONTROL);
	draw_msg(ctx->mlx, x, y, ctx->mode->msg);
	ft_sprintf(ctx->mode->msg, "%s %.0f / %.0f / %.0f", MSG_MODEL_ROTATION, \
		ctx->transform->model_angle.x,
		ctx->transform->model_angle.y,
		ctx->transform->model_angle.z);
	draw_msg(ctx->mlx, x, y, ctx->mode->msg);
	ft_sprintf(ctx->mode->msg, "%s %.3f / %.0f / %.0f", MSG_VIEW_ROTATION, \
		ctx->transform->view_angle.x,
		ctx->transform->view_angle.y,
		ctx->transform->view_angle.z);
	draw_msg(ctx->mlx, x, y, ctx->mode->msg);
}

void	draw_screen_translation_msg(t_ctx *ctx, int x, int *y)
{
	if (ctx->mode->projection == FPS)
		return ;
	ft_sprintf(ctx->mode->msg, "%s", MSG_SCREEN_TRANSLATION);
	draw_msg(ctx->mlx, x, y, ctx->mode->msg);
	ft_sprintf(ctx->mode->msg, "%s", MSG_SCREEN_TRANSLATION_CONTROL);
	draw_msg(ctx->mlx, x, y, ctx->mode->msg);
	ft_sprintf(ctx->mode->msg, "%s %.0f / %.0f",
		MSG_SCREEN_TRANSLATION_STATUS,
		ctx->transform->screen_translation.x,
		ctx->transform->screen_translation.y);
	draw_msg(ctx->mlx, x, y, ctx->mode->msg);
}

void	draw_fps_mode_msg(t_ctx *ctx, int x, int *y)
{
	if (ctx->mode->projection != FPS)
		return ;
	ft_sprintf(ctx->mode->msg, "%s %d / %d", MSG_FPS_PLAYER_POS, \
				ctx->transform->player.x, ctx->transform->player.z);
	draw_msg(ctx->mlx, x, y, ctx->mode->msg);
	ft_sprintf(ctx->mode->msg, "%s", MSG_FPS_PLAYER_POS_CONTROL);
	draw_msg(ctx->mlx, x, y, ctx->mode->msg);
	ft_sprintf(ctx->mode->msg, "%s %.0f / %.0f",
		MSG_FPS_PLAYER_ANGLE,
		ctx->transform->player_angle.x,
		ctx->transform->player_angle.y);
	draw_msg(ctx->mlx, x, y, ctx->mode->msg);
	ft_sprintf(ctx->mode->msg, "%s", MSG_FPS_PLAYER_ANGLE_CONTROL);
	draw_msg(ctx->mlx, x, y, ctx->mode->msg);
}

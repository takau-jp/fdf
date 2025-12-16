/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 15:19:22 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/14 13:46:42 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

bool	graphical_mode_key(int keycode, t_ctx *ctx);
bool	control_mode_key(int keycode, t_ctx *ctx);
bool	translation_key(int keycode, t_ctx *ctx);

int	key_press_hook(int keycode, t_ctx *ctx)
{
	if (keycode == XK_Escape)
		mlx_loop_end(ctx->mlx->mlx_ptr);
	else if (keycode == XK_BackSpace)
	{
		reset_transform(ctx->transform, ctx->mode);
		transform(ctx->map, ctx->transform, ctx->mode);
		redraw_window(ctx);
	}
	else if (keycode == XK_Shift_L || keycode == XK_Shift_R)
		ctx->mlx->is_shift_pressed = true;
	else if (graphical_mode_key(keycode, ctx))
		return (0);
	else if (control_mode_key(keycode, ctx))
		return (0);
	else if (translation_key(keycode, ctx))
		return (0);
	return (0);
}

bool	graphical_mode_key(int keycode, t_ctx *ctx)
{
	if (keycode == XK_p)
	{
		increment_in_range(&(ctx->mode->projection), PARALLEL, FPS);
		if (ctx->mode->projection == PARALLEL)
			ctx->mode->scale = MODEL_SCALE;
		else if (ctx->mode->projection == PERSPECTIVE)
			ctx->mode->scale = ZOOM_SCALE;
		if (ctx->mode->projection == FPS)
			ctx->mode->scale = ZOOM_SCALE;
	}
	else if (keycode == XK_c)
		increment_in_range(&(ctx->mode->color), DEFAULT, GEOMETRIC);
	else if (keycode == XK_l && (ctx->mode->projection != PARALLEL))
	{
		increment_in_range(&(ctx->mode->lens), STANDARD, SUPER_TELEPHOTO);
		set_lens(ctx->transform, ctx->mode, ctx->mode->lens);
	}
	else
		return (false);
	transform(ctx->map, ctx->transform, ctx->mode);
	redraw_window(ctx);
	return (true);
}

bool	control_mode_key(int keycode, t_ctx *ctx)
{
	if (keycode == XK_space)
		ctx->mode->control_panel_visible = !(ctx->mode->control_panel_visible);
	else if (keycode == XK_t)
		increment_in_range(&(ctx->mode->translation), \
							MODEL_TRANSLATION, VIEW_TRANSLATION);
	else if (keycode == XK_r)
		increment_in_range(&(ctx->mode->rotation), \
							NORMAL_ROTATION, VIEW_ROTATION);
	else if (keycode == XK_s && ctx->mode->projection == PERSPECTIVE)
		increment_in_range(&(ctx->mode->scale), ZOOM_SCALE, MODEL_SCALE);
	else
		return (false);
	redraw_window(ctx);
	return (true);
}

bool	translation_key(int keycode, t_ctx *ctx)
{
	if (keycode == XK_x || keycode == XK_y || keycode == XK_z)
	{
		if (ctx->mode->translation == MODEL_TRANSLATION)
			change_model_translation(keycode, ctx->mlx, ctx->transform);
		else
			change_view_translation(keycode, ctx->mlx, ctx->transform);
	}
	else if (keycode == XK_Left || keycode == XK_Up \
		|| keycode == XK_Right || keycode == XK_Down)
	{
		if (ctx->mode->projection == FPS)
		{
			if (!change_player_position(keycode, ctx->map, ctx->transform))
				return (true);
		}
		else
			change_screen_translation(keycode, ctx->transform);
	}
	else
		return (false);
	transform(ctx->map, ctx->transform, ctx->mode);
	redraw_window(ctx);
	return (true);
}

int	key_release_hook(int keycode, t_ctx *ctx)
{
	if (keycode == XK_Shift_L || keycode == XK_Shift_R)
		ctx->mlx->is_shift_pressed = false;
	return (0);
}

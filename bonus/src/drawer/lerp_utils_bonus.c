/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lerp_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 12:12:28 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/13 14:13:01 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	split_rgb(t_color *color);

t_point	lerp_to_near_clip(t_ctx *ctx, t_point out, t_point in)
{
	t_point		p;
	const int	color_mode = ctx->mode->color;
	double		alpha;

	alpha = (ctx->transform->near - out.view.z) / (in.view.z - out.view.z);
	p.view.x = out.view.x + alpha * (in.view.x - out.view.x);
	p.view.y = out.view.y + alpha * (in.view.y - out.view.y);
	p.view.z = ctx->transform->near;
	p.view.w = p.view.z;
	p.pixel.x = p.view.x * W_WIDTH / (2.0 * p.view.w);
	p.pixel.y = -p.view.y * W_HEIGHT / (2.0 * p.view.w);
	p.pixel.x += ctx->transform->screen_translation.x;
	p.pixel.y += ctx->transform->screen_translation.y;
	p.pixel.z_depth = p.view.z;
	p.pixel.color.rgb \
		= lerp_color(out.colors[color_mode], in.colors[color_mode], alpha);
	split_rgb(&(p.pixel.color));
	return (p);
}

// Linear Interpolation
t_screen	lerp_pixel(t_screen	start, t_screen end, double alpha)
{
	t_screen	pixel;

	pixel.x = round(start.x + (end.x - start.x) * alpha);
	pixel.y = round(start.y + (end.y - start.y) * alpha);
	pixel.z_depth = start.z_depth + (end.z_depth - start.z_depth) * alpha;
	pixel.color.rgb \
		= lerp_color(start.color, end.color, alpha);
	split_rgb(&(pixel.color));
	return (pixel);
}

int	lerp_color(t_color start, t_color end, double alpha)
{
	int	r;
	int	g;
	int	b;

	if (start.rgb == end.rgb)
		return (start.rgb);
	r = (int)round(alpha * (end.r - start.r) + start.r);
	g = (int)round(alpha * (end.g - start.g) + start.g);
	b = (int)round(alpha * (end.b - start.b) + start.b);
	return ((r << 16) | (g << 8) | b);
}

static void	split_rgb(t_color *color)
{
	color->r = (double)((color->rgb >> 16) & 0xFF);
	color->g = (double)((color->rgb >> 8) & 0xFF);
	color->b = (double)(color->rgb & 0xFF);
}

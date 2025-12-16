/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_blend_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 09:23:05 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/13 14:12:10 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	split_rgb(t_color *color);
void		apply_alpha_to_channels(t_color *color, double alpha);
int			blend_color(t_color dst_color, t_color src_color);

int	source_over_alpha_blend(\
		int dst_rgb, double dst_alpha, int src_rgb, double src_alpha)
{
	double			alpha;
	t_color			dst_color;
	t_color			src_color;

	alpha = dst_alpha + src_alpha - dst_alpha * src_alpha;
	if (alpha == 0)
		return (dst_rgb);
	dst_color.rgb = dst_rgb;
	split_rgb(&dst_color);
	src_color.rgb = src_rgb;
	split_rgb(&src_color);
	apply_alpha_to_channels(&dst_color, (dst_alpha * (1 - src_alpha)) / alpha);
	apply_alpha_to_channels(&src_color, src_alpha / alpha);
	return (blend_color(dst_color, src_color));
}

static void	split_rgb(t_color *color)
{
	color->r = (double)((color->rgb >> 16) & 0xFF);
	color->g = (double)((color->rgb >> 8) & 0xFF);
	color->b = (double)(color->rgb & 0xFF);
}

void	apply_alpha_to_channels(t_color *color, double alpha)
{
	color->r *= alpha;
	color->g *= alpha;
	color->b *= alpha;
}

int	blend_color(t_color dst_color, t_color src_color)
{
	int	r;
	int	g;
	int	b;

	r = (int)fmin(dst_color.r + src_color.r, 255.0);
	g = (int)fmin(dst_color.g + src_color.g, 255.0);
	b = (int)fmin(dst_color.b + src_color.b, 255.0);
	return ((r << 16) | (g << 8) | b);
}

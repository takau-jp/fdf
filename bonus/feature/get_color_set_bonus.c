/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_set_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:45:30 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/13 14:13:19 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int		lerp_my_color(int start_color, int end_color, double alpha);

int	get_color_set1(double color_level)
{
	if (color_level <= 1.0)
		return (lerp_my_color(0x66CCFF, 0xCCFF99, color_level));
	if (color_level <= 2.0)
		return (lerp_my_color(0xCCFF99, 0xFF99CC, color_level - 1.0));
	return (0xFF99CC);
}

int	get_color_set2(double color_level)
{
	if (color_level <= 1.0)
		return (lerp_my_color(0x0066FF, 0x9933FF, color_level));
	if (color_level <= 2.0)
		return (lerp_my_color(0x9933FF, 0xFF0033, color_level - 1.0));
	return (0xFF0033);
}

int	get_color_set3(double color_level)
{
	if (color_level <= 0.5)
		return (lerp_my_color(0x003366, 0x0066CC, color_level / 0.5));
	else if (color_level <= 1.0)
		return (lerp_my_color(0x0066CC, 0x66CCFF, (color_level - 0.5) / 0.5));
	return (0x66CCFF);
}

int	get_geometric_color(double geo_level)
{
	if (geo_level <= 0)
		return (lerp_my_color(0x0033CC, 0x0033CC, 1));
	else if (geo_level <= 1.0)
		return (lerp_my_color(0x339966, 0x66CC66, (geo_level) / 1.0));
	else if (geo_level <= 1.6)
		return (lerp_my_color(0xCC9966, 0x999999, (geo_level - 1.0) / 0.6));
	else if (geo_level < 2.0)
		return (lerp_my_color(0x999999, 0xFFFFFF, (geo_level - 1.6) / 0.4));
	else
		return (0xFFFFFF);
}

int	lerp_my_color(int start_color, int end_color, double alpha)
{
	t_color	start;
	t_color	end;
	int		r;
	int		g;
	int		b;

	start.r = (double)((start_color >> 16) & 0xFF);
	start.g = (double)((start_color >> 8) & 0xFF);
	start.b = (double)(start_color & 0xFF);
	end.r = (double)((end_color >> 16) & 0xFF);
	end.g = (double)((end_color >> 8) & 0xFF);
	end.b = (double)(end_color & 0xFF);
	r = (int)round(alpha * (end.r - start.r) + start.r);
	g = (int)round(alpha * (end.g - start.g) + start.g);
	b = (int)round(alpha * (end.b - start.b) + start.b);
	return ((r << 16) | (g << 8) | b);
}

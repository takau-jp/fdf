/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lerp_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 12:12:28 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/13 15:29:03 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Linear Interpolation
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

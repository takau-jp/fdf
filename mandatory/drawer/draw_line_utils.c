/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:55:54 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/13 15:25:58 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_line	set_line_info(t_screen start, t_screen end)
{
	t_line	line;
	int		dx;
	int		dy;

	ft_bzero(&line, sizeof(t_line));
	dx = end.x - start.x;
	line.abs_dx = abs(dx);
	if (dx != 0)
		line.inv_dx = 1.0 / dx;
	dy = end.y - start.y;
	line.abs_dy = abs(dy);
	if (dy != 0)
		line.inv_dy = 1.0 / dy;
	line.dz_depth = end.z_depth - start.z_depth;
	if (dx > 0)
		line.x_step = 1;
	else if (dx < 0)
		line.x_step = -1;
	if (dy > 0)
		line.y_step = 1;
	else if (dy < 0)
		line.y_step = -1;
	return (line);
}

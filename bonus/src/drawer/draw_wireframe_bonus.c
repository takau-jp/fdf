/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wireframe_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 20:57:27 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/14 12:41:29 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	draw_wireframe(t_ctx *ctx)
{
	int		col;
	int		row;
	t_map	*map;

	map = ctx->map;
	if (map->row_size == 1 && map->col_size == 1 \
		&& map->points[0][0].out_of_fov == false)
		draw_pixel(ctx->mlx, map->points[0][0].pixel);
	row = 0;
	while (row < map->row_size)
	{
		col = 0;
		while (col < map->col_size)
		{
			if (col != map->col_size - 1)
				draw_line(ctx, \
					map->points[row][col], map->points[row][col + 1]);
			if (row != map->row_size - 1)
				draw_line(ctx, \
					map->points[row][col], map->points[row + 1][col]);
			col++;
		}
		row++;
	}
}

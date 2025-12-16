/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wireframe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 20:57:27 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/14 12:59:34 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_wireframe(t_map *map, t_mlx *mlx)
{
	int		col;
	int		row;

	if (map->row_size == 1 && map->col_size == 1)
		draw_pixel(mlx, map->points[0][0].pixel);
	row = 0;
	while (row < map->row_size)
	{
		col = 0;
		while (col < map->col_size)
		{
			if (col != map->col_size - 1)
				draw_line(mlx, \
					map->points[row][col], map->points[row][col + 1]);
			if (row != map->row_size - 1)
				draw_line(mlx, \
					map->points[row][col], map->points[row + 1][col]);
			col++;
		}
		row++;
	}
}

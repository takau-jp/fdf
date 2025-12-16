/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 23:56:34 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/13 16:01:08 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	orthographic_projection(t_map *map)
{
	int		col;
	int		row;
	t_point	*p;

	row = 0;
	while (row < map->row_size)
	{
		col = 0;
		while (col < map->col_size)
		{
			p = &(map->points[row][col]);
			p->pixel.x = round(p->view.x) + W_WIDTH / 2;
			p->pixel.y = round(-p->view.y) + W_HEIGHT / 2;
			p->pixel.z_depth = p->view.z;
			col++;
		}
		row++;
	}
}

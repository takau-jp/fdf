/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_centroid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:53:53 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/14 13:09:45 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	update_3d_bounds(t_transform *transform, double x, double y, double z);

void	calc_centroid(t_map *map, t_transform *transform)
{
	int		col;
	int		row;
	t_point	p;

	row = 0;
	while (row < map->row_size)
	{
		col = 0;
		while (col < map->col_size)
		{
			p = map->points[row][col];
			update_3d_bounds(transform, p.model.x, p.model.y, p.model.z);
			col++;
		}
		row++;
	}
	transform->centroid = (t_3d){\
		(transform->max_3d.x + transform->min_3d.x) / 2.0, \
		(transform->max_3d.y + transform->min_3d.y) / 2.0, \
		(transform->max_3d.z + transform->min_3d.z) / 2.0};
}

void	update_3d_bounds(t_transform *transform, double x, double y, double z)
{
	if (x < transform->min_3d.x)
		transform->min_3d.x = x;
	if (x > transform->max_3d.x)
		transform->max_3d.x = x;
	if (y < transform->min_3d.y)
		transform->min_3d.y = y;
	if (y > transform->max_3d.y)
		transform->max_3d.y = y;
	if (z < transform->min_3d.z)
		transform->min_3d.z = z;
	if (z > transform->max_3d.z)
		transform->max_3d.z = z;
}

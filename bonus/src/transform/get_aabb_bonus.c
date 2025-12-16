/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_aabb_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 15:58:51 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/14 13:46:55 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	update_aabb(t_aabb *aabb, double x, double y, double z);

t_aabb	get_aabb(t_map *map)
{
	t_aabb	aabb;
	int		col;
	int		row;
	t_point	p;

	row = 0;
	aabb.max = (t_3d){-INFINITY, -INFINITY, -INFINITY};
	aabb.min = (t_3d){INFINITY, INFINITY, INFINITY};
	while (row < map->row_size)
	{
		col = 0;
		while (col < map->col_size)
		{
			p = map->points[row][col];
			update_aabb(&aabb, p.view.x, p.view.y, p.view.z);
			col++;
		}
		row++;
	}
	return (aabb);
}

void	update_aabb(t_aabb *aabb, double x, double y, double z)
{
	if (x < aabb->min.x)
		aabb->min.x = x;
	if (x > aabb->max.x)
		aabb->max.x = x;
	if (y < aabb->min.y)
		aabb->min.y = y;
	if (y > aabb->max.y)
		aabb->max.y = y;
	if (z < aabb->min.z)
		aabb->min.z = z;
	if (z > aabb->max.z)
		aabb->max.z = z;
}

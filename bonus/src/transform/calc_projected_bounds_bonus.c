/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_projected_bounds_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 20:43:00 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/15 12:23:48 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	update_2d_bounds(t_transform *transform, double x, double y);

void	calc_iso_projected_bounds(t_map *map, t_transform *transform)
{
	int				col;
	int				row;
	t_4d			p_model;
	const double	cos30 = cos(30 * DEG_TO_RAD);
	const double	sin30 = sin(30 * DEG_TO_RAD);

	row = 0;
	while (row < map->row_size)
	{
		col = 0;
		while (col < map->col_size)
		{
			p_model = map->points[row][col].model;
			update_2d_bounds(transform, \
				p_model.x * cos30 + p_model.z * cos30, \
				-p_model.x * sin30 + p_model.z * sin30 - p_model.y \
			);
			col++;
		}
		row++;
	}
}

void	update_2d_bounds(t_transform *transform, double x, double y)
{
	if (x < transform->min_2d.x)
		transform->min_2d.x = x;
	else if (x > transform->max_2d.x)
		transform->max_2d.x = x;
	if (y < transform->min_2d.y)
		transform->min_2d.y = y;
	else if (y > transform->max_2d.y)
		transform->max_2d.y = y;
}

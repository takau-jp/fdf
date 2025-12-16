/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 23:56:34 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/16 16:23:48 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	orthographic_projection(\
			t_map *map, t_transform *transform, t_mode *mode)
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
			p->pixel.x = round(p->view.x + transform->screen_translation.x);
			p->pixel.y = round(-p->view.y + transform->screen_translation.y);
			p->pixel.z_depth = p->view.z;
			p->pixel.color = p->colors[mode->color];
			p->out_of_fov = false;
			col++;
		}
		row++;
	}
}

void	perspective_projection(t_map *map, t_transform *transform, t_mode *mode)
{
	int		col;
	int		row;
	t_point	*p;

	row = -1;
	while (++row < map->row_size)
	{
		col = -1;
		while (++col < map->col_size)
		{
			p = &(map->points[row][col]);
			if (p->view.w < transform->near)
				p->out_of_fov = true;
			else
			{
				p->pixel.x = round(p->view.x * W_WIDTH / (2 * p->view.w) \
								+ transform->screen_translation.x);
				p->pixel.y = round(-p->view.y * W_HEIGHT / (2 * p->view.w) \
								+ transform->screen_translation.y);
				p->pixel.z_depth = p->view.z; // z / w ?
				p->pixel.color = p->colors[mode->color];
				p->out_of_fov = false;
			}
		}
	}
}

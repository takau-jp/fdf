/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_modes_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:37:53 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/13 14:13:23 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	init_color_mode_and_height_bounds(t_map *map, t_mode *mode);

void	init_modes(t_map *map, t_transform *transform, t_mode *mode)
{
	mode->control_panel_visible = true;
	mode->projection = PARALLEL;
	init_color_mode_and_height_bounds(map, mode);
	set_my_colors(map);
	mode->translation = VIEW_TRANSLATION;
	mode->rotation = NORMAL_ROTATION;
	set_lens(transform, mode, STANDARD);
	mode->scale = MODEL_SCALE;
}

void	init_color_mode_and_height_bounds(t_map *map, t_mode *mode)
{
	int	col;
	int	row;

	map->max_height = -INFINITY;
	map->min_height = INFINITY;
	mode->color = SET_1;
	if (map->col_size == 250 && map->row_size == 256)
		mode->color = GEOMETRIC;
	row = 0;
	while (row < map->row_size)
	{
		col = 0;
		while (col < map->col_size)
		{
			if (mode->color != DEFAULT \
				&& map->points[row][col].colors[DEFAULT].rgb != 0xFFFFFF)
				mode->color = DEFAULT;
			if (map->points[row][col].model.y > map->max_height)
				map->max_height = map->points[row][col].model.y;
			if (map->points[row][col].model.y < map->min_height)
				map->min_height = map->points[row][col].model.y;
			col++;
		}
		row++;
	}
}

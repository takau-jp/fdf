/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_my_colors_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 23:15:45 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/13 14:13:30 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void		apply_color_sets(t_point *p, double color_level, double geo_level);
static void	split_rgb(t_color *color);

void	set_my_colors(t_map *map)
{
	int				col;
	int				row;
	const double	step = (map->max_height - map->min_height) / 2.0;
	double			color_level;
	double			geo_level;

	row = -1;
	while (++row < map->row_size)
	{
		col = -1;
		while (++col < map->col_size)
		{
			if (step > 0.0)
				color_level \
					= (map->points[row][col].model.y - map->min_height) / step;
			else
				color_level = 0.0;
			if (map->max_height > 0.0 && map->points[row][col].model.y > 0)
				geo_level \
					= (map->points[row][col].model.y) * 2.0 / map->max_height;
			else
				geo_level = 0.0;
			apply_color_sets(&(map->points[row][col]), color_level, geo_level);
		}
	}
}

void	apply_color_sets(t_point *p, double color_level, double geo_level)
{
	p->colors[SET_1].rgb = get_color_set1(color_level);
	split_rgb(&(p->colors[SET_1]));
	p->colors[SET_2].rgb = get_color_set2(color_level);
	split_rgb(&(p->colors[SET_2]));
	p->colors[SET_3].rgb = get_color_set3(color_level);
	split_rgb(&(p->colors[SET_3]));
	p->colors[GEOMETRIC].rgb = get_geometric_color(geo_level);
	split_rgb(&(p->colors[GEOMETRIC]));
}

static void	split_rgb(t_color *color)
{
	color->r = (double)((color->rgb >> 16) & 0xFF);
	color->g = (double)((color->rgb >> 8) & 0xFF);
	color->b = (double)(color->rgb & 0xFF);
}

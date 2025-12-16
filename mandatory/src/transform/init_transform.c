/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_transform.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:28:03 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/13 15:59:55 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	calc_initial_scale(t_transform *transform);

void	init_transform(t_map *map, t_transform *transform)
{
	calc_centroid(map, transform);
	calc_iso_projected_bounds(map, transform);
	calc_initial_scale(transform);
}

void	calc_initial_scale(t_transform *transform)
{
	double	width;
	double	height;
	double	scale_x;
	double	scale_y;

	width = transform->max_2d.x - transform->min_2d.x + 1;
	height = transform->max_2d.y - transform->min_2d.y + 1;
	scale_x = W_WIDTH / width;
	scale_y = W_HEIGHT / height;
	if (scale_x <= scale_y)
		transform->model_scale = scale_x * 0.9;
	else
		transform->model_scale = scale_y * 0.9;
}

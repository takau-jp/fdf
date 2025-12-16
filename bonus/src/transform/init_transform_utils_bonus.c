/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_transform_utils_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:28:03 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/14 13:54:53 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	calc_initial_scale(t_transform *transform);

void	init_transform(t_map *map, t_transform *transform, t_mode *mode)
{
	if (map->col_size > map->row_size)
		map->size = map->col_size;
	else
		map->size = map->row_size;
	calc_centroid(map, transform);
	calc_iso_projected_bounds(map, transform);
	reset_transform(transform, mode);
	transform->model_scale_max = transform->model_scale * 100.0;
}

void	reset_transform(t_transform *transform, t_mode *mode)
{
	ft_bzero(&(transform->model_translation), sizeof(t_3d));
	ft_bzero(&(transform->view_translation), sizeof(t_3d));
	transform->screen_translation.x = W_WIDTH / 2.0;
	transform->screen_translation.y = W_HEIGHT / 2.0;
	calc_initial_scale(transform);
	ft_bzero(&(transform->model_rotation), sizeof(t_quaternion));
	transform->model_rotation.w = 1.0;
	ft_bzero(&(transform->model_angle), sizeof(t_euler_angle));
	ft_bzero(&(transform->view_rotation), sizeof(t_quaternion));
	transform->view_rotation.w = 1.0;
	ft_bzero(&(transform->view_angle), sizeof(t_euler_angle));
	transform->view_angle.y = 45.0;
	transform->view_angle.x = 35.264;
	set_lens(transform, mode, STANDARD);
	transform->player.x = round(transform->centroid.x);
	transform->player.z = round(transform->centroid.z);
	ft_bzero(&(transform->player_angle), sizeof(t_euler_angle));
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

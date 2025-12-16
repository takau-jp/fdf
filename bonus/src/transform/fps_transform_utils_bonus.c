/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps_transform_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 23:05:08 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/14 13:53:23 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

t_3d	set_player_pos(t_map *map, t_transform *transform)
{
	t_3d	player_pos;

	player_pos.x = \
		-map->points[transform->player.z][transform->player.x].view.x;
	player_pos.y = \
		-(map->points[transform->player.z][transform->player.x].view.y \
			+ 4 * transform->model_scale_max);
	player_pos.z = \
		-map->points[transform->player.z][transform->player.x].view.z;
	return (player_pos);
}

t_affine_matrix	make_player_angle_matrix(t_transform *transform)
{
	t_affine_matrix	y_rotation;
	t_affine_matrix	x_rotation;

	y_rotation = make_y_rotation_matrix_euler(-transform->player_angle.y);
	x_rotation = make_x_rotation_matrix_euler(transform->player_angle.x);
	return (affine_matrix_multiply(x_rotation, y_rotation));
}

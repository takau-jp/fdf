/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tkyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 15:58:02 by stanaka2          #+#    #+#             */
/*   Updated: 2025/10/30 12:55:25 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	model_transform(t_transform *transform);
void	view_transform(t_transform *transform);

void	transformation(t_map *map, t_transform *transform)
{
	model_transform(transform);
	view_transform(transform);
	affine_transform(map, transform->affine_matrix);
}

void	model_transform(t_transform *transform)
{
	t_affine_matrix	centroid_translation;
	t_affine_matrix	scale;

	transform->affine_matrix = make_identity_matrix();
	centroid_translation = make_translation_matrix(\
								invert_pos_3d(transform->centroid));
	scale = make_scale_matrix(transform->model_scale);
	transform->affine_matrix = affine_matrix_multiply(\
			centroid_translation, transform->affine_matrix);
	transform->affine_matrix = affine_matrix_multiply(\
			scale, transform->affine_matrix);
}

// atan2(1.0, sqrt(2.0) * RAD_TO_DEG == 35.264
void	view_transform(t_transform *transform)
{
	t_affine_matrix	y_rotation;
	t_affine_matrix	x_rotation;

	y_rotation = make_y_rotation_matrix_euler(-45);
	x_rotation \
		= make_x_rotation_matrix_euler(-atan2(1.0, sqrt(2.0)) * RAD_TO_DEG);
	transform->affine_matrix = affine_matrix_multiply(\
			y_rotation, transform->affine_matrix);
	transform->affine_matrix = affine_matrix_multiply(\
			x_rotation, transform->affine_matrix);
}

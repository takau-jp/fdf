/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:19:17 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/13 14:19:30 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	model_transform(t_transform *transform, t_mode *mode);
void	view_transform(t_transform *transform, t_mode *mode);
void	clip_transform(t_map *map, t_transform *transform);
void	fps_clip_transform(t_map *map, t_transform *transform);

void	transform(t_map *map, t_transform *transform, t_mode *mode)
{
	model_transform(transform, mode);
	view_transform(transform, mode);
	if (mode->projection == PERSPECTIVE)
		clip_transform(map, transform);
	else if (mode->projection == FPS)
		fps_clip_transform(map, transform);
	affine_transform(map, transform->affine_matrix);
	if (mode->projection == PERSPECTIVE || mode->projection == FPS)
		perspective_projection(map, transform, mode);
	else if (mode->projection == PARALLEL)
		orthographic_projection(map, transform, mode);
}

void	model_transform(t_transform *transform, t_mode *mode)
{
	t_affine_matrix	centroid_translation;
	t_affine_matrix	scale;
	t_affine_matrix	rotation;
	t_affine_matrix	translation;

	transform->affine_matrix = make_identity_matrix();
	centroid_translation = make_translation_matrix(\
								invert_pos_3d(transform->centroid));
	if (mode->projection == FPS)
		scale = make_scale_matrix(transform->model_scale_max);
	else
		scale = make_scale_matrix(transform->model_scale);
	rotation = make_rotation_matrix_quaternion(transform->model_rotation);
	translation = make_translation_matrix(transform->model_translation);
	transform->affine_matrix = affine_matrix_multiply(\
			centroid_translation, transform->affine_matrix);
	transform->affine_matrix = affine_matrix_multiply(\
			scale, transform->affine_matrix);
	if (mode->projection == FPS)
		return ;
	transform->affine_matrix = affine_matrix_multiply(\
			rotation, transform->affine_matrix);
	transform->affine_matrix = affine_matrix_multiply(\
			translation, transform->affine_matrix);
}

void	view_transform(t_transform *transform, t_mode *mode)
{
	t_affine_matrix	init_view;
	t_affine_matrix	rotation;
	t_affine_matrix	translation;

	if (mode->projection == FPS)
		return ;
	init_view = make_init_view_matrix();
	rotation = make_rotation_matrix_quaternion(transform->view_rotation);
	translation = make_translation_matrix(\
			invert_pos_3d(transform->view_translation));
	transform->affine_matrix = affine_matrix_multiply(\
			init_view, transform->affine_matrix);
	transform->affine_matrix = affine_matrix_multiply(\
			rotation, transform->affine_matrix);
	transform->affine_matrix = affine_matrix_multiply(\
			translation, transform->affine_matrix);
}

void	clip_transform(t_map *map, t_transform *transform)
{
	t_aabb			aabb;
	t_affine_matrix	z_translation;
	t_affine_matrix	calc_w;
	t_affine_matrix	clip;
	double			camera_offset;

	camera_offset = map->size * transform->model_scale / 4;
	affine_transform(map, transform->affine_matrix);
	aabb = get_aabb(map);
	z_translation = make_translation_matrix(\
						(t_3d){0, 0, camera_offset - aabb.min.z});
	transform->affine_matrix = affine_matrix_multiply(\
			z_translation, transform->affine_matrix);
	aabb.max.z += camera_offset - aabb.min.z;
	calc_w = make_calc_w_matrix();
	transform->zoom_y = transform->zoom_scale;
	transform->zoom_x = W_WIDTH / W_HEIGHT * transform->zoom_scale;
	transform->near = Z_NEAR_CLIP;
	transform->far = aabb.max.z;
	clip = make_clip_matrix(transform);
	transform->affine_matrix = affine_matrix_multiply(\
			calc_w, transform->affine_matrix);
	transform->affine_matrix = affine_matrix_multiply(\
			clip, transform->affine_matrix);
}

void	fps_clip_transform(t_map *map, t_transform *transform)
{
	t_affine_matrix	player_translation;
	t_affine_matrix	player_angle;
	t_affine_matrix	calc_w;
	t_affine_matrix	clip;

	affine_transform(map, transform->affine_matrix);
	player_translation \
		= make_translation_matrix(set_player_pos(map, transform));
	player_angle = make_player_angle_matrix(transform);
	calc_w = make_calc_w_matrix();
	transform->zoom_y = transform->zoom_scale;
	transform->zoom_x = W_WIDTH / W_HEIGHT * transform->zoom_scale;
	transform->near = Z_NEAR_CLIP;
	transform->far = get_aabb(map).max.z;
	clip = make_clip_matrix(transform);
	transform->affine_matrix = affine_matrix_multiply(
			player_translation, transform->affine_matrix);
	transform->affine_matrix = affine_matrix_multiply(
			player_angle, transform->affine_matrix);
	transform->affine_matrix = affine_matrix_multiply(
			calc_w, transform->affine_matrix);
	transform->affine_matrix = affine_matrix_multiply(
			clip, transform->affine_matrix);
}

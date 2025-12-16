/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_affine_rotation_matrix_bonus.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 22:29:45 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/26 16:40:52 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

t_affine_matrix	make_rotation_matrix_quaternion(t_quaternion quaternion)
{
	t_affine_matrix	matrix;
	const double	w = quaternion.w;
	const double	x = quaternion.x;
	const double	y = quaternion.y;
	const double	z = quaternion.z;

	set_matrix_row(matrix.m[0], (double [4]){\
		1 - 2 * (y * y + z * z), 2 * (x * y - w * z), 2 * (x * z + w * y), 0});
	set_matrix_row(matrix.m[1], (double [4]){\
		2 * (x * y + w * z), 1 - 2 * (x * x + z * z), 2 * (y * z - w * x), 0});
	set_matrix_row(matrix.m[2], (double [4]){\
		2 * (x * z - w * y), 2 * (y * z + w * x), 1 - 2 * (x * x + y * y), 0});
	set_matrix_row(matrix.m[3], (double [4]){0, 0, 0, 1});
	return (matrix);
}

t_affine_matrix	make_x_rotation_matrix_euler(double deg)
{
	t_affine_matrix	matrix;
	const double	s = sin(deg * DEG_TO_RAD);
	const double	c = cos(deg * DEG_TO_RAD);

	set_matrix_row(matrix.m[0], (double [4]){1, 0, 0, 0});
	set_matrix_row(matrix.m[1], (double [4]){0, c, -s, 0});
	set_matrix_row(matrix.m[2], (double [4]){0, s, c, 0});
	set_matrix_row(matrix.m[3], (double [4]){0, 0, 0, 1});
	return (matrix);
}

t_affine_matrix	make_y_rotation_matrix_euler(double deg)
{
	t_affine_matrix	matrix;
	const double	s = sin(deg * DEG_TO_RAD);
	const double	c = cos(deg * DEG_TO_RAD);

	set_matrix_row(matrix.m[0], (double [4]){c, 0, s, 0});
	set_matrix_row(matrix.m[1], (double [4]){0, 1, 0, 0});
	set_matrix_row(matrix.m[2], (double [4]){-s, 0, c, 0});
	set_matrix_row(matrix.m[3], (double [4]){0, 0, 0, 1});
	return (matrix);
}

t_affine_matrix	make_z_rotation_matrix_euler(double deg)
{
	t_affine_matrix	matrix;
	const double	s = sin(deg * DEG_TO_RAD);
	const double	c = cos(deg * DEG_TO_RAD);

	set_matrix_row(matrix.m[0], (double [4]){c, -s, 0, 0});
	set_matrix_row(matrix.m[1], (double [4]){s, c, 0, 0});
	set_matrix_row(matrix.m[2], (double [4]){0, 0, 1, 0});
	set_matrix_row(matrix.m[3], (double [4]){0, 0, 0, 1});
	return (matrix);
}

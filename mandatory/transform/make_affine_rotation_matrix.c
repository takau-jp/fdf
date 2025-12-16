/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_affine_rotation_matrix.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 22:29:45 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/13 15:33:21 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

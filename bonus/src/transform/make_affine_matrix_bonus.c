/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_affine_matrix_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 19:43:38 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/13 14:18:59 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

t_affine_matrix	make_identity_matrix(void)
{
	t_affine_matrix	matrix;

	set_matrix_row(matrix.m[0], (double [4]){1, 0, 0, 0});
	set_matrix_row(matrix.m[1], (double [4]){0, 1, 0, 0});
	set_matrix_row(matrix.m[2], (double [4]){0, 0, 1, 0});
	set_matrix_row(matrix.m[3], (double [4]){0, 0, 0, 1});
	return (matrix);
}

t_affine_matrix	make_scale_matrix(double scale)
{
	t_affine_matrix	matrix;

	set_matrix_row(matrix.m[0], (double [4]){scale, 0, 0, 0});
	set_matrix_row(matrix.m[1], (double [4]){0, scale, 0, 0});
	set_matrix_row(matrix.m[2], (double [4]){0, 0, scale, 0});
	set_matrix_row(matrix.m[3], (double [4]){0, 0, 0, 1});
	return (matrix);
}

t_affine_matrix	make_translation_matrix(t_3d translation)
{
	t_affine_matrix	matrix;

	set_matrix_row(matrix.m[0], (double [4]){1, 0, 0, translation.x});
	set_matrix_row(matrix.m[1], (double [4]){0, 1, 0, translation.y});
	set_matrix_row(matrix.m[2], (double [4]){0, 0, 1, translation.z});
	set_matrix_row(matrix.m[3], (double [4]){0, 0, 0, 1});
	return (matrix);
}

void	set_matrix_row(double matrix_row[4], double row[4])
{
	matrix_row[0] = row[0];
	matrix_row[1] = row[1];
	matrix_row[2] = row[2];
	matrix_row[3] = row[3];
}

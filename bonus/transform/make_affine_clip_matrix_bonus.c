/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_affine_clip_matrix_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 04:02:04 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/13 14:18:55 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

t_affine_matrix	make_calc_w_matrix(void)
{
	t_affine_matrix	matrix;

	set_matrix_row(matrix.m[0], (double [4]){1, 0, 0, 0});
	set_matrix_row(matrix.m[1], (double [4]){0, 1, 0, 0});
	set_matrix_row(matrix.m[2], (double [4]){0, 0, 1, 1});
	set_matrix_row(matrix.m[3], (double [4]){0, 0, 0, 0});
	return (matrix);
}

t_affine_matrix	make_clip_matrix(t_transform *transform)
{
	t_affine_matrix	matrix;
	const double	n = transform->near;
	const double	f = transform->far;

	if (n == f)
		return (make_identity_matrix());
	set_matrix_row(matrix.m[0], (double [4]){transform->zoom_x, 0, 0, 0});
	set_matrix_row(matrix.m[1], (double [4]){0, transform->zoom_y, 0, 0});
	set_matrix_row(matrix.m[2], (double [4]){0, 0, -f / (-f - -n), 1});
	set_matrix_row(matrix.m[3], (double [4]){0, 0, (-n * -f) / (-n - -f), 0});
	return (matrix);
}

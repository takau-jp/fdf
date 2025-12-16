/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_init_view_matrix_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 00:23:08 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/13 14:19:07 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

// atan2(1.0, sqrt(2.0) * RAD_TO_DEG == 35.264
t_affine_matrix	make_init_view_matrix(void)
{
	t_affine_matrix	y_rotation;
	t_affine_matrix	x_rotation;

	y_rotation = make_y_rotation_matrix_euler(-45);
	x_rotation \
		= make_x_rotation_matrix_euler(-atan2(1.0, sqrt(2.0)) * RAD_TO_DEG);
	return (affine_matrix_multiply(x_rotation, y_rotation));
}

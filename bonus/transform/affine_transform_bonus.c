/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affine_transform_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 23:06:43 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/14 13:50:49 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

t_affine_matrix	affine_matrix_multiply(
	t_affine_matrix multiplier, t_affine_matrix multiplicand)
{
	t_affine_matrix	result;
	int				i;
	int				j;
	int				k;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			k = 0;
			result.m[i][j] = 0;
			while (k < 4)
			{
				result.m[i][j] += multiplier.m[i][k] * multiplicand.m[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
	return (result);
}

void	affine_transform(t_map *map, t_affine_matrix affine_matrix)
{
	int	col;
	int	row;

	row = 0;
	while (row < map->row_size)
	{
		col = 0;
		while (col < map->col_size)
		{
			apply_affine_transform(\
				&(map->points[row][col]), affine_matrix.m);
			col++;
		}
		row++;
	}
}

void	apply_affine_transform(t_point *point, double matrix[4][4])
{
	const double	m_x = point->model.x;
	const double	m_y = point->model.y;
	const double	m_z = point->model.z;
	const double	m_w = point->model.w;

	point->view.x = m_x * matrix[0][0] + m_y * matrix[0][1] \
							+ m_z * matrix[0][2] + m_w * matrix[0][3];
	point->view.y = m_x * matrix[1][0] + m_y * matrix[1][1] \
							+ m_z * matrix[1][2] + m_w * matrix[1][3];
	point->view.z = m_x * matrix[2][0] + m_y * matrix[2][1] \
							+ m_z * matrix[2][2] + m_w * matrix[2][3];
	point->view.w = m_x * matrix[3][0] + m_y * matrix[3][1] \
							+ m_z * matrix[3][2] + m_w * matrix[3][3];
}

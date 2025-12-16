/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:41:09 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/26 16:25:27 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

t_quaternion	make_quaternion(char axis, double deg)
{
	t_quaternion	quaternion;

	quaternion.w = cos((deg * DEG_TO_RAD) / 2);
	quaternion.x = 0.0;
	quaternion.y = 0.0;
	quaternion.z = 0.0;
	if (axis == 'x' || axis == 'X')
		quaternion.x = sin((deg * DEG_TO_RAD) / 2);
	else if (axis == 'y' || axis == 'Y')
		quaternion.y = sin((deg * DEG_TO_RAD) / 2);
	else if (axis == 'z' || axis == 'Z')
		quaternion.z = sin((deg * DEG_TO_RAD) / 2);
	return (quaternion);
}

t_quaternion	quaternion_multiply(
	t_quaternion multiplier, t_quaternion multiplicand)
{
	t_quaternion	result;

	result.w = (multiplier.w * multiplicand.w) - (multiplier.x * multiplicand.x)
		- (multiplier.y * multiplicand.y) - (multiplier.z * multiplicand.z);
	result.x = (multiplier.w * multiplicand.x) + (multiplier.x * multiplicand.w)
		- (multiplier.y * multiplicand.z) + (multiplier.z * multiplicand.y);
	result.y = (multiplier.w * multiplicand.y) + (multiplier.y * multiplicand.w)
		- (multiplier.z * multiplicand.x) + (multiplier.x * multiplicand.z);
	result.z = (multiplier.w * multiplicand.z) + (multiplier.z * multiplicand.w)
		- (multiplier.x * multiplicand.y) + (multiplier.y * multiplicand.x);
	return (result);
}

void	quaternion_normalize(t_quaternion *q)
{
	double	norm_squared;
	double	norm;

	norm_squared = q->w * q->w + q->x * q->x + q->y * q->y + q->z * q->z;
	if (fabs(norm_squared - 1.0) > 1e-6)
	{
		norm = sqrt(norm_squared);
		if (norm == 0.0)
		{
			q->w = 1.0;
			q->x = 0.0;
			q->y = 0.0;
			q->z = 0.0;
			return ;
		}
		q->w /= norm;
		q->x /= norm;
		q->y /= norm;
		q->z /= norm;
	}
}

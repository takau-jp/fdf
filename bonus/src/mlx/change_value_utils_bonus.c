/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_value_utils_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 08:24:12 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/14 13:58:37 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	increment_in_range(int *value, int min, int max)
{
	if (*value == max)
		*value = min;
	else
		*value += 1;
}

void	decrement_in_range(int *value, int min, int max)
{
	if (*value == min)
		*value = max;
	else
		*value -= 1;
}

void	change_with_limit(int *value, int delta, int min, int max)
{
	if (delta < 0 && *value < min - delta)
		*value = min;
	else if (delta > 0 && *value > max - delta)
		*value = max;
	else
		*value += delta;
}

void	change_double_with_limit(\
			double *value, double delta, double min, double max)
{
	if (delta < 0 && *value < min - delta)
		*value = min;
	else if (delta > 0 && *value > max - delta)
		*value = max;
	else
		*value += delta;
}

void	change_euler_angle(double *angle, double delta)
{
	*angle += delta;
	if (*angle > 180.0)
		*angle -= 360.0;
	else if (*angle <= -180.0)
		*angle += 360.0;
}

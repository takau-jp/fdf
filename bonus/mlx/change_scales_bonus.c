/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_scales_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 04:18:54 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/13 14:14:09 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

bool	change_model_scale(unsigned int button, t_transform *transform)
{
	if (button == Button4)
	{
		if (transform->model_scale == transform->model_scale_max)
			return (false);
		if (transform->model_scale == 0.0)
			transform->model_scale = 0.001;
		else
			transform->model_scale *= 1.1;
		if (transform->model_scale > transform->model_scale_max)
			transform->model_scale = transform->model_scale_max;
	}
	else if (button == Button5)
	{
		if (transform->model_scale == 0.0)
			return (false);
		transform->model_scale *= 0.9;
		if (transform->model_scale < 0.001)
			transform->model_scale = 0.0;
	}
	return (true);
}

bool	change_zoom_scale(\
			unsigned int button, t_transform *transform, t_mode *mode)
{
	if (button == Button4)
	{
		if (transform->zoom_scale == 100.0)
			return (false);
		transform->zoom_scale *= 1.1;
		if (transform->zoom_scale > 100.0)
			transform->zoom_scale = 100;
	}
	else if (button == Button5)
	{
		if (transform->zoom_scale == 0.1)
			return (false);
		transform->zoom_scale *= 0.9;
		if (transform->zoom_scale < 0.1)
			transform->zoom_scale = 0.1;
	}
	set_scale_mode(transform, mode);
	return (true);
}

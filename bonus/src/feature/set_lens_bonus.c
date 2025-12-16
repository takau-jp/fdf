/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_lens_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:01:41 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/13 14:13:26 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	set_lens(t_transform *transform, t_mode *mode, int lens_type)
{
	if (lens_type == WIDE)
	{
		transform->zoom_scale = 0.7;
		mode->lens = WIDE;
	}
	else if (lens_type == SUPER_WIDE)
	{
		transform->zoom_scale = 0.4;
		mode->lens = SUPER_WIDE;
	}
	else if (lens_type == TELEPHOTO)
	{
		transform->zoom_scale = 3.0;
		mode->lens = TELEPHOTO;
	}
	else if (lens_type == SUPER_TELEPHOTO)
	{
		transform->zoom_scale = 8.0;
		mode->lens = SUPER_TELEPHOTO;
	}
	else
	{
		transform->zoom_scale = 1.0;
		mode->lens = STANDARD;
	}
}

void	set_scale_mode(t_transform *transform, t_mode *mode)
{
	if (transform->zoom_scale >= 5.0)
	{
		mode->lens = SUPER_TELEPHOTO;
	}
	else if (transform->zoom_scale >= 2.0)
	{
		mode->lens = TELEPHOTO;
	}
	else if (transform->zoom_scale >= 0.8)
	{
		mode->lens = STANDARD;
	}
	else if (transform->zoom_scale >= 0.6)
	{
		mode->lens = WIDE;
	}
	else
	{
		mode->lens = SUPER_WIDE;
	}
}

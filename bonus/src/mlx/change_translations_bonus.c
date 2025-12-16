/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_translations_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:59:08 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/14 14:05:46 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	change_model_translation(
			int keycode, t_mlx *mlx, t_transform *transform)
{
	t_3d	*model_translation;
	double	delta;

	model_translation = &(transform->model_translation);
	delta = 10.0;
	if (mlx->is_shift_pressed)
		delta = -10.0;
	if (keycode == XK_x)
		change_double_with_limit(&(model_translation->x), delta, \
									-TRANSLATION_LIMIT, TRANSLATION_LIMIT);
	else if (keycode == XK_y)
		change_double_with_limit(&(model_translation->y), delta, \
									-TRANSLATION_LIMIT, TRANSLATION_LIMIT);
	else if (keycode == XK_z)
		change_double_with_limit(&(model_translation->z), delta, \
									-TRANSLATION_LIMIT, TRANSLATION_LIMIT);
}

void	change_view_translation(
			int keycode, t_mlx *mlx, t_transform *transform)
{
	t_3d	*view_translation;
	double	delta;

	view_translation = &(transform->view_translation);
	delta = 10.0;
	if (mlx->is_shift_pressed)
		delta = -10.0;
	if (keycode == XK_x)
		change_double_with_limit(&(view_translation->x), delta, \
									-TRANSLATION_LIMIT, TRANSLATION_LIMIT);
	else if (keycode == XK_y)
		change_double_with_limit(&(view_translation->y), delta, \
									-TRANSLATION_LIMIT, TRANSLATION_LIMIT);
	else if (keycode == XK_z)
		change_double_with_limit(&(view_translation->z), delta, \
									-TRANSLATION_LIMIT, TRANSLATION_LIMIT);
}

void	change_screen_translation(int keycode, t_transform *transform)
{
	t_2d	*screen_translation;
	double	delta;

	delta = 10.0;
	if (keycode == XK_Left || keycode == XK_Down)
		delta = -10.0;
	screen_translation = &(transform->screen_translation);
	if (keycode == XK_Left)
		change_double_with_limit(&(screen_translation->x), delta, \
									-TRANSLATION_LIMIT, TRANSLATION_LIMIT);
	else if (keycode == XK_Up)
		change_double_with_limit(&(screen_translation->y), delta, \
									-TRANSLATION_LIMIT, TRANSLATION_LIMIT);
	else if (keycode == XK_Right)
		change_double_with_limit(&(screen_translation->x), delta, \
									-TRANSLATION_LIMIT, TRANSLATION_LIMIT);
	else if (keycode == XK_Down)
		change_double_with_limit(&(screen_translation->y), delta, \
									-TRANSLATION_LIMIT, TRANSLATION_LIMIT);
}

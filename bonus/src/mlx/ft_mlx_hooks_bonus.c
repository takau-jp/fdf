/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_hooks_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 01:07:11 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/26 15:27:27 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	ft_mlx_hooks(\
			t_map *map, t_transform *transform, t_mlx *mlx, t_mode *mode)
{
	t_ctx	ctx;

	ctx.map = map;
	ctx.transform = transform;
	ctx.mlx = mlx;
	ctx.mode = mode;
	mlx_expose_hook(mlx->win_ptr, expose_hook, &ctx);
	mlx_hook(mlx->win_ptr, KeyRelease, KeyReleaseMask, \
		key_release_hook, &ctx);
	mlx_hook(mlx->win_ptr, KeyPress, KeyPressMask, \
		key_press_hook, &ctx);
	mlx_hook(mlx->win_ptr, ButtonPress, ButtonPressMask, \
		button_press_hook, &ctx);
	mlx_hook(mlx->win_ptr, MotionNotify, Button1MotionMask, \
		button1_motion_hook, &ctx);
	mlx_hook(mlx->win_ptr, ClientMessage, NoEventMask, \
		mlx_loop_end, mlx->mlx_ptr);
	mlx_loop(mlx->mlx_ptr);
}

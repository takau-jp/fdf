/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 01:07:11 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/19 19:47:36 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_mlx_hooks(t_mlx *mlx)
{
	mlx_expose_hook(mlx->win_ptr, expose_hook, mlx);
	mlx_hook(mlx->win_ptr, KeyPress, KeyPressMask, \
		key_press_hook, mlx);
	mlx_hook(mlx->win_ptr, ClientMessage, NoEventMask, \
		mlx_loop_end, mlx->mlx_ptr);
	mlx_loop(mlx->mlx_ptr);
}

int	expose_hook(t_mlx *mlx)
{
	redraw_window(mlx);
	return (0);
}

int	key_press_hook(int keycode, t_mlx *mlx)
{
	if (keycode == XK_Escape)
		mlx_loop_end(mlx->mlx_ptr);
	return (0);
}

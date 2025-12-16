/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_player_angle_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 02:42:51 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/13 14:13:53 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

bool	change_player_angle(int x, int y, t_ctx *ctx)
{
	const int		dx = (x - ctx->mlx->mouse.x) / PIXEL_PER_ROTATE;
	const int		dy = (y - ctx->mlx->mouse.y) / PIXEL_PER_ROTATE;

	if (dx == 0 && dy == 0)
		return (false);
	if (dx != 0)
	{
		change_euler_angle(&(ctx->transform->player_angle.y), dx);
		ctx->mlx->mouse = (t_2d){x, y};
	}
	else if (dy != 0)
	{
		if (dy < 0 && ctx->transform->player_angle.x == 89)
			return (false);
		else if (dy > 0 && ctx->transform->player_angle.x == -89)
			return (false);
		change_euler_angle(&(ctx->transform->player_angle.x), -dy);
		ctx->mlx->mouse = (t_2d){x, y};
		if (dy < 0 && ctx->transform->player_angle.x > 89)
			ctx->transform->player_angle.x = 89;
		else if (dy > 0 && ctx->transform->player_angle.x < -89)
			ctx->transform->player_angle.x = -89;
	}
	return (true);
}

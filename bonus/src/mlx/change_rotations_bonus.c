/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_rotations_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 04:17:19 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/13 14:14:06 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

bool	change_normal_rotation(int x, int y, t_ctx *ctx)
{
	t_quaternion	*m_rote;
	t_quaternion	*v_rote;
	const int		dx = (x - ctx->mlx->mouse.x) / PIXEL_PER_ROTATE;
	const int		dy = (y - ctx->mlx->mouse.y) / PIXEL_PER_ROTATE;

	if (dx == 0 && dy == 0)
		return (false);
	m_rote = &(ctx->transform->model_rotation);
	v_rote = &(ctx->transform->view_rotation);
	if (dx != 0)
	{
		*m_rote = quaternion_multiply(make_quaternion('y', -dx), *m_rote);
		quaternion_normalize(m_rote);
		change_euler_angle(&(ctx->transform->model_angle.y), -dx);
		ctx->mlx->mouse = (t_2d){x, y};
	}
	if (dy != 0)
	{
		*v_rote = quaternion_multiply(make_quaternion('x', -dy), *v_rote);
		quaternion_normalize(v_rote);
		change_euler_angle(&(ctx->transform->view_angle.x), -dy);
		ctx->mlx->mouse = (t_2d){x, y};
	}
	return (true);
}

bool	change_model_rotation(int x, int y, t_ctx *ctx)
{
	t_quaternion	*m_rote;
	const int		dx = (x - ctx->mlx->mouse.x) / PIXEL_PER_ROTATE;
	const int		dy = (y - ctx->mlx->mouse.y) / PIXEL_PER_ROTATE;

	if (dx == 0 && dy == 0)
		return (false);
	m_rote = &(ctx->transform->model_rotation);
	if (dx != 0)
	{
		*m_rote = quaternion_multiply(make_quaternion('z', -dx), *m_rote);
		quaternion_normalize(m_rote);
		change_euler_angle(&(ctx->transform->model_angle.z), -dx);
		ctx->mlx->mouse = (t_2d){x, y};
	}
	if (dy != 0)
	{
		*m_rote = quaternion_multiply(make_quaternion('x', -dy), *m_rote);
		quaternion_normalize(m_rote);
		change_euler_angle(&(ctx->transform->model_angle.x), -dy);
		ctx->mlx->mouse = (t_2d){x, y};
	}
	return (true);
}

bool	change_view_rotation(int x, int y, t_ctx *ctx)
{
	t_quaternion	*v_rote;
	const int		dx = (x - ctx->mlx->mouse.x) / PIXEL_PER_ROTATE;
	const int		dy = (y - ctx->mlx->mouse.y) / PIXEL_PER_ROTATE;

	if (dx == 0 && dy == 0)
		return (false);
	v_rote = &(ctx->transform->view_rotation);
	if (dx != 0)
	{
		*v_rote = quaternion_multiply(make_quaternion('y', -dx), *v_rote);
		quaternion_normalize(v_rote);
		change_euler_angle(&(ctx->transform->view_angle.y), -dx);
		ctx->mlx->mouse = (t_2d){x, y};
	}
	if (dy != 0)
	{
		*v_rote = quaternion_multiply(make_quaternion('z', -dy), *v_rote);
		quaternion_normalize(v_rote);
		change_euler_angle(&(ctx->transform->view_angle.z), -dy);
		ctx->mlx->mouse = (t_2d){x, y};
	}
	return (true);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose_hook_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:12:31 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/13 14:14:23 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	expose_hook(t_ctx *ctx)
{
	transform(ctx->map, ctx->transform, ctx->mode);
	redraw_window(ctx);
	return (0);
}

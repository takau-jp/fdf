/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invert_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 22:29:00 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/13 15:41:23 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_3d	invert_pos_3d(t_3d pos)
{
	t_3d	inv_pos;

	inv_pos.x = -pos.x;
	inv_pos.y = -pos.y;
	inv_pos.z = -pos.z;
	return (inv_pos);
}

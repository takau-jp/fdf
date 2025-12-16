/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invert_pos_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 22:29:00 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/13 14:18:51 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

t_3d	invert_pos_3d(t_3d pos)
{
	t_3d	inv_pos;

	inv_pos.x = -pos.x;
	inv_pos.y = -pos.y;
	inv_pos.z = -pos.z;
	return (inv_pos);
}

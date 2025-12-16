/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_get_pixel_addr.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 20:52:51 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/13 14:24:32 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int	*ft_mlx_get_pixel_addr(t_img img, int x, int y)
{
	char	*pixel_addr;

	pixel_addr = (img.pixel \
		+ (y * img.size_line) + (x * (img.bits_per_pixel / 8)));
	return ((unsigned int *)pixel_addr);
}

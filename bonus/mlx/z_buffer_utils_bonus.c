/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_buffer_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:58:38 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/13 14:14:57 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

bool	create_z_buffer(t_img *img)
{
	int	i;
	int	j;

	img->z_buffer = (double **)malloc(sizeof(double *) * W_HEIGHT);
	if (img->z_buffer == NULL)
		return (false);
	i = 0;
	while (i < W_HEIGHT)
	{
		img->z_buffer[i] = malloc(sizeof(double) * W_WIDTH);
		if (img->z_buffer[i] == NULL)
		{
			while (i > 0)
				free(img->z_buffer[--i]);
			free(img->z_buffer);
			return (false);
		}
		j = 0;
		while (j < W_WIDTH)
			img->z_buffer[i][j++] = INFINITY;
		i++;
	}
	return (true);
}

void	reset_z_buffer(t_img *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < W_HEIGHT)
	{
		j = 0;
		while (j < W_WIDTH)
		{
			img->z_buffer[i][j] = INFINITY;
			j++;
		}
		i++;
	}
}

void	clear_z_buffer(t_img *img)
{
	int	i;

	i = 0;
	while (i < W_HEIGHT)
		free(img->z_buffer[i++]);
	free(img->z_buffer);
}

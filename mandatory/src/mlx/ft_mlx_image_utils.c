/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_image_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:16:04 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/13 15:19:25 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_image(t_img *img, int width, int height);
bool	ft_mlx_create_image(t_mlx *mlx, t_img *img);

bool	ft_mlx_init_model_image(t_mlx *mlx)
{
	t_img	*model_img;

	model_img = &(mlx->model_img);
	init_image(model_img, W_WIDTH, W_HEIGHT);
	if (!create_z_buffer(model_img))
		return (false);
	if (!ft_mlx_create_image(mlx, model_img))
		return (false);
	return (true);
}

void	init_image(t_img *img, int width, int height)
{
	img->img_ptr = NULL;
	img->width = width;
	img->height = height;
	img->pixel = NULL;
	img->bits_per_pixel = COLOR_BIT_SIZE;
	img->size_line = img->width;
	img->endian = LITTLE_ENDIAN;
}

bool	ft_mlx_create_image(t_mlx *mlx, t_img *img)
{
	img->img_ptr = mlx_new_image(mlx->mlx_ptr, img->width, img->height);
	if (img->img_ptr == NULL)
		return (false);
	img->pixel = mlx_get_data_addr(img->img_ptr, \
					&(img->bits_per_pixel), &(img->size_line), &(img->endian));
	if (img->pixel == NULL)
		return (false);
	return (true);
}

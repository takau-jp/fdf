/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 22:28:41 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/13 15:28:02 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line_x(\
				t_mlx *mlx, t_screen start, t_screen end, t_line line);
void	draw_line_y(\
				t_mlx *mlx, t_screen start, t_screen end, t_line line);
void	draw_line_x_no_lerp_color(\
				t_mlx *mlx, t_screen start, t_screen end, t_line line);
void	draw_line_y_no_lerp_color(\
				t_mlx *mlx, t_screen start, t_screen end, t_line line);

void	draw_line(t_mlx *mlx, t_point start, t_point end)
{
	t_line	line;

	line = set_line_info(start.pixel, end.pixel);
	if (start.pixel.color.rgb == end.pixel.color.rgb)
	{
		if (line.abs_dx >= line.abs_dy)
			draw_line_x_no_lerp_color(mlx, start.pixel, end.pixel, line);
		else
			draw_line_y_no_lerp_color(mlx, start.pixel, end.pixel, line);
	}
	else
	{
		if (line.abs_dx >= line.abs_dy)
			draw_line_x(mlx, start.pixel, end.pixel, line);
		else
			draw_line_y(mlx, start.pixel, end.pixel, line);
	}
}

void	draw_line_x(\
			t_mlx *mlx, t_screen start, t_screen end, t_line line)
{
	t_screen	pixel;

	pixel = start;
	line.error = 0;
	while (pixel.x != end.x)
	{
		draw_pixel(mlx, pixel);
		pixel.x += line.x_step;
		line.error += 2 * line.abs_dy;
		if (line.error >= line.abs_dx)
		{
			pixel.y += line.y_step;
			line.error -= 2 * line.abs_dx;
		}
		line.alpha = (pixel.x - start.x) * line.inv_dx;
		pixel.color.rgb = lerp_color(start.color, end.color, line.alpha);
		pixel.z_depth = start.z_depth + line.dz_depth * line.alpha;
	}
	draw_pixel(mlx, end);
}

void	draw_line_y(\
			t_mlx *mlx, t_screen start, t_screen end, t_line line)
{
	t_screen	pixel;

	pixel = start;
	line.error = 0;
	while (pixel.y != end.y)
	{
		draw_pixel(mlx, pixel);
		pixel.y += line.y_step;
		line.error += 2 * line.abs_dx;
		if (line.error >= line.abs_dy)
		{
			pixel.x += line.x_step;
			line.error -= 2 * line.abs_dy;
		}
		line.alpha = (pixel.y - start.y) * line.inv_dy;
		pixel.color.rgb = lerp_color(start.color, end.color, line.alpha);
		pixel.z_depth = start.z_depth + line.dz_depth * line.alpha;
	}
	draw_pixel(mlx, end);
}

void	draw_line_x_no_lerp_color(\
			t_mlx *mlx, t_screen start, t_screen end, t_line line)
{
	t_screen	pixel;

	pixel = start;
	line.error = 0;
	while (pixel.x != end.x)
	{
		draw_pixel(mlx, pixel);
		pixel.x += line.x_step;
		line.error += 2 * line.abs_dy;
		if (line.error >= line.abs_dx)
		{
			pixel.y += line.y_step;
			line.error -= 2 * line.abs_dx;
		}
		line.alpha = (pixel.x - start.x) * line.inv_dx;
		pixel.z_depth = start.z_depth + line.dz_depth * line.alpha;
	}
	draw_pixel(mlx, end);
}

void	draw_line_y_no_lerp_color(\
			t_mlx *mlx, t_screen start, t_screen end, t_line line)
{
	t_screen	pixel;

	pixel = start;
	line.error = 0;
	while (pixel.y != end.y)
	{
		draw_pixel(mlx, pixel);
		pixel.y += line.y_step;
		line.error += 2 * line.abs_dx;
		if (line.error >= line.abs_dy)
		{
			pixel.x += line.x_step;
			line.error -= 2 * line.abs_dy;
		}
		line.alpha = (pixel.y - start.y) * line.inv_dy;
		pixel.z_depth = start.z_depth + line.dz_depth * line.alpha;
	}
	draw_pixel(mlx, end);
}

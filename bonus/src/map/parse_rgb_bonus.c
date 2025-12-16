/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 12:43:16 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/13 14:13:47 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	read_color(char *rgb);
int	hex_to_decimal(char hex);

void	parse_rgb(t_color *color, char *rgb)
{
	if (rgb == NULL || ft_strncmp(rgb, ",0x", 3) || ft_strlen(rgb) > 9)
	{
		color->rgb = 0xFFFFFF;
		color->r = (double)(0xFF);
		color->g = (double)(0xFF);
		color->b = (double)(0xFF);
		return ;
	}
	color->rgb = read_color(rgb + 3);
	color->r = (double)((color->rgb >> 16) & 0xFF);
	color->g = (double)((color->rgb >> 8) & 0xFF);
	color->b = (double)(color->rgb & 0xFF);
}

int	read_color(char *rgb)
{
	int	color;
	int	decimal;

	color = 0;
	while (*rgb)
	{
		decimal = hex_to_decimal(*rgb);
		if (decimal == -1)
			return (0xFFFFFF);
		color = color * 16 + decimal;
		rgb++;
	}
	return (color);
}

int	hex_to_decimal(char hex)
{
	if ('a' <= hex && hex <= 'f')
		return (hex - 'a' + 10);
	else if ('A' <= hex && hex <= 'F')
		return (hex - 'A' + 10);
	else if ('0' <= hex && hex <= '9')
		return (hex - '0');
	else
		return (-1);
}

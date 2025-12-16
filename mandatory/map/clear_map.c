/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 13:48:30 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/13 14:24:32 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear_map(t_map *map)
{
	int	row;

	row = 0;
	while (row < map->row_size)
	{
		free(map->points[row]);
		row++;
	}
	free(map->points);
}

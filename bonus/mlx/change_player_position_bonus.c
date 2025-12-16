/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_player_position_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 22:24:50 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/13 14:14:01 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

bool	change_player_position_angle0(\
			int keycode, t_map *map, t_player_pos *player);
bool	change_player_position_angle90(\
			int keycode, t_map *map, t_player_pos *player);
bool	change_player_position_angle180(\
			int keycode, t_map *map, t_player_pos *player);
bool	change_player_position_angle270(\
			int keycode, t_map *map, t_player_pos *player);

bool	change_player_position(int keycode, t_map *map, t_transform *transform)
{
	const double	y_angle = transform->player_angle.y;

	if (-45 <= y_angle && y_angle < 45)
	{
		if (!change_player_position_angle0(keycode, map, &(transform->player)))
			return (false);
	}
	if (45 <= y_angle && y_angle < 135)
	{
		if (!change_player_position_angle90(keycode, map, &(transform->player)))
			return (false);
	}
	if (135 <= y_angle || y_angle < -135)
	{
		if (!change_player_position_angle180(\
				keycode, map, &(transform->player)))
			return (false);
	}
	if (-135 <= y_angle && y_angle < -45)
	{
		if (!change_player_position_angle270(\
				keycode, map, &(transform->player)))
			return (false);
	}
	return (true);
}

bool	change_player_position_angle0(\
			int keycode, t_map *map, t_player_pos *player)
{
	if (keycode == XK_Up)
	{
		if (player->z == 0)
			return (false);
		change_with_limit(&(player->z), -1, 0, map->row_size - 1);
	}
	if (keycode == XK_Down)
	{
		if (player->z == map->row_size - 1)
			return (false);
		change_with_limit(&(player->z), 1, 0, map->row_size - 1);
	}
	else if (keycode == XK_Left)
	{
		if (player->x == 0)
			return (false);
		change_with_limit(&(player->x), -1, 0, map->col_size - 1);
	}
	else if (keycode == XK_Right)
	{
		if (player->x == map->col_size - 1)
			return (false);
		change_with_limit(&(player->x), 1, 0, map->col_size - 1);
	}
	return (true);
}

bool	change_player_position_angle90(\
			int keycode, t_map *map, t_player_pos *player)
{
	if (keycode == XK_Up)
	{
		if (player->x == map->col_size - 1)
			return (false);
		change_with_limit(&(player->x), 1, 0, map->col_size - 1);
	}
	else if (keycode == XK_Down)
	{
		if (player->x == 0)
			return (false);
		change_with_limit(&(player->x), -1, 0, map->col_size - 1);
	}
	else if (keycode == XK_Left)
	{
		if (player->z == 0)
			return (false);
		change_with_limit(&(player->z), -1, 0, map->row_size - 1);
	}
	else if (keycode == XK_Right)
	{
		if (player->z == map->row_size - 1)
			return (false);
		change_with_limit(&(player->z), 1, 0, map->row_size - 1);
	}
	return (true);
}

bool	change_player_position_angle180(\
			int keycode, t_map *map, t_player_pos *player)
{
	if (keycode == XK_Up)
	{
		if (player->z == map->row_size - 1)
			return (false);
		change_with_limit(&(player->z), 1, 0, map->row_size - 1);
	}
	else if (keycode == XK_Down)
	{
		if (player->z == 0)
			return (false);
		change_with_limit(&(player->z), -1, 0, map->row_size - 1);
	}
	else if (keycode == XK_Left)
	{
		if (player->x == map->col_size - 1)
			return (false);
		change_with_limit(&(player->x), 1, 0, map->col_size - 1);
	}
	else if (keycode == XK_Right)
	{
		if (player->x == 0)
			return (false);
		change_with_limit(&(player->x), -1, 0, map->col_size - 1);
	}
	return (true);
}

bool	change_player_position_angle270(\
			int keycode, t_map *map, t_player_pos *player)
{
	if (keycode == XK_Up)
	{
		if (player->x == 0)
			return (false);
		change_with_limit(&(player->x), -1, 0, map->col_size - 1);
	}
	else if (keycode == XK_Down)
	{
		if (player->x == map->col_size - 1)
			return (false);
		change_with_limit(&(player->x), 1, 0, map->col_size - 1);
	}
	else if (keycode == XK_Left)
	{
		if (player->z == map->row_size - 1)
			return (false);
		change_with_limit(&(player->z), 1, 0, map->row_size - 1);
	}
	else if (keycode == XK_Right)
	{
		if (player->z == 0)
			return (false);
		change_with_limit(&(player->z), -1, 0, map->row_size - 1);
	}
	return (true);
}

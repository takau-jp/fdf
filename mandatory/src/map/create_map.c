/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 01:25:04 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/14 12:42:47 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	***convert_lst_to_map_data(t_list *lst);
bool	check_map_size(t_map *map, char ***map_data);
bool	allocate_map(t_map *map);
void	parse_map(t_map *map, char ***map_data);

void	create_map(t_map *map, char *map_file_path)
{
	t_list	*lst;
	char	***map_data;

	lst = read_file_as_lst(map_file_path);
	map_data = convert_lst_to_map_data(lst);
	if (map_data == NULL)
	{
		ft_lstclear(&lst, free);
		errno_error("malloc");
	}
	if (!check_map_size(map, map_data))
	{
		ft_lstclear(&lst, free);
		clear_map_data(map_data);
		invalid_map_error("This map is too large or contains invalid row.");
	}
	if (!allocate_map(map))
	{
		ft_lstclear(&lst, free);
		clear_map_data(map_data);
		errno_error("malloc");
	}
	parse_map(map, map_data);
	ft_lstclear(&lst, free);
	clear_map_data(map_data);
}

char	***convert_lst_to_map_data(t_list *lst)
{
	char	***map_data;
	size_t	size;
	size_t	row;

	size = ft_sizet_lstsize(lst);
	map_data = (char ***)malloc(sizeof(char **) * (size + 1));
	if (map_data == NULL)
		return (NULL);
	row = 0;
	while (lst)
	{
		map_data[row] = ft_split_set(lst->content, " \n");
		if (map_data[row] == NULL)
		{
			while (row-- > 0)
				free_splitted(map_data[row]);
			free(map_data);
			return (NULL);
		}
		lst = lst->next;
		row++;
	}
	map_data[row] = NULL;
	return (map_data);
}

bool	check_map_size(t_map *map, char ***map_data)
{
	size_t	col;
	size_t	row;

	row = 0;
	while (map_data[row] != NULL)
	{
		col = 0;
		while (map_data[row][col] != NULL)
		{
			if (!check_int(map_data[row][col]))
				return (false);
			col++;
		}
		if (col > (size_t)INT_MAX)
			return (false);
		else if (row == 0)
			map->col_size = (int)col;
		else if (map->col_size != (int)col)
			return (false);
		row++;
	}
	if (row > (size_t)INT_MAX)
		return (false);
	map->row_size = row;
	return (true);
}

bool	allocate_map(t_map *map)
{
	int	row;

	map->points = (t_point **)malloc(sizeof(t_point *) * map->row_size);
	if (map->points == NULL)
		return (false);
	row = 0;
	while (row < map->row_size)
	{
		map->points[row] = (t_point *)malloc(sizeof(t_point) * map->col_size);
		if (map->points[row] == NULL)
		{
			while (row-- > 0)
				free(map->points[row]);
			free(map->points);
			return (false);
		}
		row++;
	}
	return (true);
}

void	parse_map(t_map *map, char ***map_data)
{
	int		col;
	int		row;
	t_point	*point;

	row = 0;
	while (row < map->row_size)
	{
		col = 0;
		while (col < map->col_size)
		{
			point = &(map->points[row][col]);
			point->model.x = (double)col;
			point->model.y = (double)ft_atoi(map_data[row][col]);
			point->model.z = (double)(map->row_size - 1 - row);
			point->model.w = 1.0;
			parse_rgb(&(point->pixel.color), \
							ft_strchr(map_data[row][col], ','));
			col++;
		}
		row++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argument_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 00:06:37 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/13 14:12:04 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	assert_map_file_extension(char *map_file_path);

void	check_argument(int argc, char **argv)
{
	if (argc != 2)
		invalid_arguments_count_error();
	assert_map_file_extension(argv[1]);
}

static void	assert_map_file_extension(char *map_file_path)
{
	size_t	len;

	len = ft_strlen(map_file_path);
	if (len < 4)
		invalid_map_file_extension_error();
	if (ft_strncmp(map_file_path + (len - 4), ".fdf", 4))
		invalid_map_file_extension_error();
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_error_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 00:08:17 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/13 14:13:04 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	invalid_arguments_count_error(void)
{
	ft_dprintf(STDERR_FILENO, "Error\n");
	ft_dprintf(STDERR_FILENO, \
		"\033[1;31mInvalid arguments.\033[0m\n\
\033[34m[Usage]: ./fdf \"path_to_map_file\"\033[0m\n");
	exit(1);
}

void	invalid_map_file_extension_error(void)
{
	ft_dprintf(STDERR_FILENO, "Error\n");
	ft_dprintf(STDERR_FILENO, \
		"\033[1;31mInvalid map file extension.\033[0m\n\
\033[34m[Usage]: The map file must have a .fdf extension.\033[0m\n");
	exit(1);
}

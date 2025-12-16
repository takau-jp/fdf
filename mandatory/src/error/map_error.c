/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 00:02:25 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/13 14:24:32 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	invalid_map_error(char *error_msg)
{
	ft_dprintf(STDERR_FILENO, "Error\n");
	ft_dprintf(STDERR_FILENO, \
		"\033[1;31mInvalid map.\033[0m\n\033[34m[Usage]: %s\033[0m\n", \
		error_msg);
	exit(1);
}

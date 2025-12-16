/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errno_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 00:32:37 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/13 14:24:32 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	errno_error(char *error_point)
{
	ft_dprintf(STDERR_FILENO, "Error\n");
	ft_dprintf(STDERR_FILENO, "\033[1;31m");
	perror(error_point);
	ft_dprintf(STDERR_FILENO, "\033[0m");
	exit(1);
}

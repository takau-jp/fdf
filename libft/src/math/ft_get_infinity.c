/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_infinity.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 04:10:15 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/06 22:38:38 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_get_infinity(void)
{
	union u_make_infinity	infinity;

	infinity.bits = 0x7FF0000000000000ULL;
	return (infinity.value);
}

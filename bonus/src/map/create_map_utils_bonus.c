/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 11:18:45 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/14 13:03:42 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

bool	is_long_overflow(long num, int sign, int n);

size_t	ft_sizet_lstsize(t_list *lst)
{
	size_t	size;

	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

void	clear_map_data(char ***map_data)
{
	int	row;

	row = 0;
	while (map_data[row] != NULL)
	{
		free_splitted(map_data[row]);
		row++;
	}
	free(map_data);
}

void	free_splitted(char **splitted)
{
	size_t	i;

	i = 0;
	while (splitted[i] != NULL)
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
}

bool	check_int(char *num)
{
	long	n;
	int		sign;

	sign = 1;
	if (*num == '+' || *num == '-')
	{
		if (*num == '-')
			sign = -1;
		num++;
	}
	if (!ft_isdigit(*num))
		return (false);
	n = 0;
	while (ft_isdigit(*num))
	{
		if (is_long_overflow(n, sign, (*num - '0')))
			return (false);
		n = n * 10 + (*num - '0');
		num++;
	}
	return (true);
}

bool	is_long_overflow(long num, int sign, int add)
{
	long	limit;

	if (sign == 1)
		limit = LONG_MAX;
	else
		limit = LONG_MIN;
	if (num > LONG_MAX / 10
		|| (num == LONG_MAX / 10 && (int)(ft_abs_ulong(limit) % 10) < add))
		return (true);
	return (false);
}

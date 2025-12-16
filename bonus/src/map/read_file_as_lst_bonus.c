/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_as_lst_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 22:35:29 by stanaka2          #+#    #+#             */
/*   Updated: 2025/11/13 14:13:50 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

char	*read_line_as_lst(int fd, t_list **lst);

t_list	*read_file_as_lst(char *map_file_path)
{
	int		fd;
	t_list	*lst;

	fd = open(map_file_path, O_RDONLY);
	if (fd == -1)
		errno_error("open");
	lst = NULL;
	if (read_line_as_lst(fd, &lst) == NULL)
	{
		close(fd);
		invalid_map_error("This map file is empty.");
	}
	while (read_line_as_lst(fd, &lst))
		;
	close(fd);
	return (lst);
}

char	*read_line_as_lst(int fd, t_list **lst)
{
	char	*line;
	t_list	*node;

	line = get_next_line(fd);
	if (errno != 0)
	{
		ft_lstclear(lst, free);
		close(fd);
		errno_error("get_next_line");
	}
	if (line == NULL)
		return (NULL);
	node = ft_lstnew(line);
	if (node == NULL)
	{
		free(line);
		ft_lstclear(lst, free);
		close(fd);
		errno_error("malloc");
	}
	ft_lstadd_back(lst, node);
	return (line);
}

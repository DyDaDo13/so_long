/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:40:14 by dydado13          #+#    #+#             */
/*   Updated: 2023/11/30 21:14:58 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_map	*init_map_struct(int fd)
{
	t_map	*lst;
	t_map	*newnode;
	t_map	*start;

	lst = malloc(sizeof(t_map));
	start = lst;
	lst->map_line = get_next_line(fd);
	while (lst->map_line)
	{
		newnode = ft_lstnew(get_next_line(fd));
		ft_lstadd_back(&lst, newnode);
		lst = lst->next;
	}
	lst = start;
	return (lst);
}

void	remove_newlines(t_data data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data.MAP[i])
	{
		while (data.MAP[i][j++])
		{
			if (data.MAP[i][j] == '\n')
				data.MAP[i][j] = '\0';
		}
		j = 0;
		i++;
	}
}

char	**init_map(int fd, t_data data)
{
	int		i;

	data.map = init_map_struct(fd);
	i = ft_lstsize(data.map);
	data.map->map_height = i;
	data.MAP = malloc(sizeof(char) * i);
	if (!data.MAP)
		return (0);
	i = 0;
	while (data.map->next)
	{
		data.MAP[i] = data.map->map_line;
		i++;
		data.map = data.map->next;
	}
	remove_newlines(data);
	return (data.MAP);
}

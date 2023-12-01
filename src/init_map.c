/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:40:14 by dydado13          #+#    #+#             */
/*   Updated: 2023/12/01 17:44:05 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_map	*init_map_struct(int fd)
{
	t_map	*lst;
	t_map	*newnode;
	t_map	*start;

	lst = malloc(sizeof(t_map));
	if (!lst)
		return (NULL);
	lst->map_line = get_next_line(fd);
	start = lst;
	while (lst->map_line)
	{
		newnode = ft_lstnew(get_next_line(fd));
		lst->next = newnode;
		lst = lst->next;
	}
	return (start);
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

char	**init_map(int fd, t_data *data)
{
	int		i;
	t_map	*cpy;

	data->map = init_map_struct(fd);
	cpy = data->map;
	i = ft_lstsize(data->map);
	data->map_height = i;
	data->MAP = malloc(sizeof(char*) * i);
	if (!data->MAP)
		return (NULL);
	i = 0;
	while (cpy)
	{
		data->MAP[i] = cpy->map_line;
		i++;
		cpy = cpy->next;
	}
	free_list(&data->map);
	remove_newlines(*data);
	return (data->MAP);
}

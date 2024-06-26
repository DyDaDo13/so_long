/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylmarti <dylmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:40:14 by dydado13          #+#    #+#             */
/*   Updated: 2023/12/04 19:56:16 by dylmarti         ###   ########.fr       */
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
	lst->next = NULL;
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
	while (data.map[i])
	{
		while (data.map[i][j++])
		{
			if (data.map[i][j] == '\n')
				data.map[i][j] = '\0';
		}
		j = 0;
		i++;
	}
}

char	**init_map(int fd, t_data *data)
{
	int		i;
	t_map	*cpy;

	data->map_char = init_map_struct(fd);
	cpy = data->map_char;
	i = ft_lstsize(data->map_char);
	data->map_height = i;
	data->map = malloc(sizeof(char *) * i);
	if (!data->map)
		return (NULL);
	i = 0;
	while (cpy)
	{
		data->map[i] = cpy->map_line;
		i++;
		cpy = cpy->next;
	}
	free_list(&data->map_char);
	remove_newlines(*data);
	return (data->map);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylmarti <dylmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 18:24:28 by dydado13          #+#    #+#             */
/*   Updated: 2023/12/04 20:00:44 by dylmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	is_wall_valid(char **map, t_data *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map[i][++j])
		if (map[i][j] != '1')
			return (1);
	i++;
	data->map_width = j;
	while (i < data->map_height - 2)
	{
		j = 0;
		while (map[i][j++])
			if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
				return (1);
		i++;
	}
	j = 0;
	while (map[i][++j])
		if (map[i][j] != '1')
			return (1);
	return (0);
}

int	is_size_valid(char **map, t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (j != data->map_width)
			return (1);
		i++;
	}
	return (0);
}

int	is_objects_valid(char **map, t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (map[++i])
	{
		j = 0;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
				data->p += 1;
			else if (map[i][j] == 'C')
				data->c += 1;
			else if (map[i][j] == 'E')
				data->e += 1;
			else if (map[i][j] != '1' && map[i][j] != '0')
				return (1);
		}
	}
	if (data->c < 1 || data->e != 1 || data->p != 1)
		return (1);
	return (0);
}

int	is_path_valid(char **map, t_data *data)
{
	t_point	*size;
	t_point	*begin;
	int		c;
	int		e;

	size = malloc(sizeof(t_point));
	begin = malloc(sizeof(t_point));
	if (size == NULL || begin == NULL)
		return (1);
	find_p(map, begin, data);
	size->x = data->map_width;
	size->y = (data->map_height - 1);
	flood_fill(map, size, begin, data);
	c = size->c;
	e = size->e;
	if (c != data->c || e != data->e)
		return (free(size), free(begin), 1);
	return (free(size), free(begin), 0);
}

int	is_map_valid(char **map, t_data *data)
{
	data->c = 0;
	data->e = 0;
	data->p = 0;
	if (map[0] && map[0][0] == '1')
	{
		if (is_wall_valid(map, data) == 1)
			return (ft_printf("\033[31mError : Wall Not Valid\033[0m\n"), 1);
		if (is_size_valid(map, data) == 1)
			return (ft_printf("\033[31mError : Size Not Valid\033[0m\n"), 1);
		if ((data->map_height - 1) == data->map_width)
			return (ft_printf("\033[31mError : Is Not Rectangle\033[0m\n"), 1);
		if (is_objects_valid(map, data) == 1)
			return (ft_printf("\033[31mError : Objects Not Valid\033[0m\n"), 1);
		if (is_path_valid(map, data) == 1)
			return (ft_printf("\033[31mError : Path Not Valid\033[0m\n"), 1);
		return (ft_printf("\033[32mMap Valid\033[0m\n"), 0);
	}
	return (ft_printf("\033[31mError : Map Not Valid\033[0m\n"), 1);
}

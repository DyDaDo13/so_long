/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 18:24:28 by dydado13          #+#    #+#             */
/*   Updated: 2023/12/01 19:14:28 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	is_wall_valid(char **map, t_data *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map[0][++j])
		if (map[0][j] != '1')
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
				data->P += 1;
			else if (map[i][j] == 'C')
				data->C += 1;
			else if (map[i][j] == 'E')
				data->E += 1;
			else if (map[i][j] != '1' && map[i][j] != '0')
				return (1);
		}
	}
	if (data->C < 1 || data->E != 1 || data->P != 1)
		return (1);
	return (0);
}

int	is_map_valid(char **map, t_data *data)
{
	if (is_wall_valid(map, data) == 1)
		return (printf("\033[31mError : Wall Not Valid\033[0m\n"), 1);
	if (is_size_valid(map, data) == 1)
		return (printf("\033[31mError : Size Not Valid\033[0m\n"), 1);
	if ((data->map_height - 1) == data->map_width)
		return (printf("\033[31mError : Is Not Rectangle\033[0m\n"), 1);
	if (is_objects_valid(map, data) == 1)
		return (printf("\033[31mError : Objects Not Valid\033[0m\n"), 1);
	return (0);
}
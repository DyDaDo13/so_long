/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylmarti <dylmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:40:39 by dylmarti          #+#    #+#             */
/*   Updated: 2023/12/04 16:15:58 by dylmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**map_dup(char **tab, t_data *data)
{
	char	**map;
	int		j;
	int		i;

	i = -1;
	map = malloc(sizeof(char *) * data->map_height);
	while (++i < (data->map_height - 1))
		map[i] = malloc(sizeof(char) * data->map_width + 1);
	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			map[i][j] = tab[i][j];
			j++;
		}
		map[i][j] = '\0';
		i++;
	}
	map[i] = NULL;
	return (map);
}

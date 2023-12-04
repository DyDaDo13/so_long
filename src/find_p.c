/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylmarti <dylmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:56:45 by dydado13          #+#    #+#             */
/*   Updated: 2023/12/04 18:34:40 by dylmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	find_p(char **map, t_point *P, t_data *data)
{
	int			i;
	int			j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				P->x = j;
				P->y = i;
				data->p_y = i;
				data->p_x = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	find_e(char **map, t_data *data)
{
	int			i;
	int			j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
			{
				data->e_y = i;
				data->e_x = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

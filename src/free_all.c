/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:35:32 by dydado13          #+#    #+#             */
/*   Updated: 2023/12/01 15:54:21 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_map(t_data data)
{
	int		i;

	i = 0;
	while (data.MAP[i])
	{
		free(data.MAP[i]);
		i++;
	}
}

void	free_list(t_map **map)
{
	t_map	*tmp;
	
	tmp = *map;
	while ((*map))
	{
		tmp = (*map)->next;
		free((*map));
		(*map) = tmp;
	}
}

void	free_all(t_data data)
{
	if (data.MAP)
	{
		free_map(data);
		free(data.MAP);
	}
}

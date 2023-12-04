/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylmarti <dylmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:13:55 by dydado13          #+#    #+#             */
/*   Updated: 2023/12/04 20:00:01 by dylmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	f_fill(char **tab, t_point *size, int row, int col)
{
	if (row < 0 || col < 0 || row >= size->y || col >= size->x)
		return ;
	if (tab[row][col] == ' ' || tab[row][col] == '1')
		return ;
	if (tab[row][col] == 'C')
		size->c += 1;
	if (tab[row][col] == 'E')
		size->e += 1;
	tab[row][col] = ' ';
	f_fill(tab, size, row -1, col);
	f_fill(tab, size, row +1, col);
	f_fill(tab, size, row, col - 1);
	f_fill(tab, size, row, col + 1);
}

void	flood_fill(char **tab, t_point *size, t_point *begin, t_data *data)
{
	char	**map;
	int		i;

	i = -1;
	size->c = 0;
	size->e = 0;
	map = map_dup(tab, data);
	f_fill(map, size, begin->y, begin->x);
	while (map[++i])
		free(map[i]);
	free(map);
}

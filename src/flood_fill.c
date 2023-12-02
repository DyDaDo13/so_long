/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:13:55 by dydado13          #+#    #+#             */
/*   Updated: 2023/12/02 15:18:17 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// void f_fill(char **tab, t_point *size, int row, int col)
// {
// 	printf("flood fill %c\n", tab[row][col]);
//     if (row < 0 || col < 0 || row >= size->y || col >= size->x)
//         return;
//     if (tab[row][col] == '1')
//         return;
//     if (tab[row][col] == 'C')
// 		size->C += 1;
// 	if (tab[row][col] == 'E')
// 		size->E += 1;
// 	tab[row][col] = " ";

//     f_fill(tab, size, row -1, col);
//     f_fill(tab, size, row +1, col);
//     f_fill(tab, size, row, col - 1);
//     f_fill(tab, size, row, col + 1);
// }

// void  flood_fill(char **tab, t_point *size, t_point *begin)
// {
// 	size->C = 0;
// 	size->E = 0;
//     f_fill(tab, size, begin->y, begin->x);
// }

void f_fill(char **tab, t_point *size, int row, int col)
{
    if (row < 0 || col < 0 || row >= size->y || col >= size->x)
		return ;
	if (tab[row][col] == ' ' || tab[row][col] == '1')
    	return ;
	if (tab[row][col] == 'C')
		size->C += 1;
	if (tab[row][col] == 'E')
		size->E += 1;
    tab[row][col] = ' ';

    f_fill(tab, size, row -1, col);
    f_fill(tab, size, row +1, col);
    f_fill(tab, size, row, col - 1);
    f_fill(tab, size, row, col + 1);
}

void  flood_fill(char **tab, t_point *size, t_point *begin)
{
	size->C = 0;
	size->E = 0;
    f_fill(tab, size, begin->y, begin->x);
}

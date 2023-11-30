/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:25:03 by dylmarti          #+#    #+#             */
/*   Updated: 2023/11/30 20:32:37 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_lstsize(t_map *lst)
{
	int		i;
	t_map	*node;

	i = 0;
	node = lst;
	while (node != NULL)
	{
		node = node->next;
		i++;
	}
	return (i);
}

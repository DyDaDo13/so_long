/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 09:40:55 by dylmarti          #+#    #+#             */
/*   Updated: 2023/11/30 17:50:19 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_map	*ft_lstnew(void *content)
{
	t_map	*newnode;

	newnode = malloc(sizeof(t_map));
	if (newnode == NULL)
		return (NULL);
	newnode->map_line = content;
	newnode->next = NULL;
	return (newnode);
}

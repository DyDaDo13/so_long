/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylmarti <dylmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:22:35 by dylmarti          #+#    #+#             */
/*   Updated: 2023/12/04 19:57:03 by dylmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	draw_images(t_data *data, int i, int j)
{
	if (data->map[i][j] == '1')
		mlx_put_image_to_window(data->mlx, data->win,
			data->sprites.walls.image, data->x, data->y);
	if (data->map[i][j] == '0')
		mlx_put_image_to_window(data->mlx, data->win,
			data->sprites.ground.image, data->x, data->y);
	if (data->map[i][j] == 'C')
		mlx_put_image_to_window(data->mlx, data->win,
			data->sprites.coin.image, data->x, data->y);
	if (data->map[i][j] == 'E')
		mlx_put_image_to_window(data->mlx, data->win,
			data->sprites.exit_close.image, data->x, data->y);
	if (data->map[i][j] == 'P')
		mlx_put_image_to_window(data->mlx, data->win,
			data->sprites.player_front.image, data->x, data->y);
}

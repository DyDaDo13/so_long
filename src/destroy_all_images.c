/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_all_images.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylmarti <dylmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:10:15 by dylmarti          #+#    #+#             */
/*   Updated: 2023/12/04 15:16:36 by dylmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	destroy_all_images(t_data *data)
{
	mlx_destroy_image(data->mlx, data->sprites.walls.image);
	mlx_destroy_image(data->mlx, data->sprites.ground.image);
	mlx_destroy_image(data->mlx, data->sprites.coin.image);
	mlx_destroy_image(data->mlx, data->sprites.exit_close.image);
	mlx_destroy_image(data->mlx, data->sprites.exit_open.image);
	mlx_destroy_image(data->mlx, data->sprites.player_back.image);
	mlx_destroy_image(data->mlx, data->sprites.player_front.image);
	mlx_destroy_image(data->mlx, data->sprites.player_left.image);
	mlx_destroy_image(data->mlx, data->sprites.player_right.image);
}

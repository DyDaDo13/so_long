/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylmarti <dylmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:45:28 by dylmarti          #+#    #+#             */
/*   Updated: 2023/12/04 15:33:40 by dylmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	init_images(t_data *data)
{
	int	x = 0;
	int	y = 0;
	data->sprites.walls.image = mlx_xpm_file_to_image(data->mlx, 
		"sprites/walls.xpm", &x, &y);
	data->sprites.walls.image_pix = mlx_get_data_addr(data->mlx,
		&data->sprites.walls.bits_per, &data->sprites.walls.line_len,
			&data->sprites.walls.endian);
	data->sprites.ground.image = mlx_xpm_file_to_image(data->mlx,
		"sprites/ground.xpm", &x, &y);
	data->sprites.ground.image_pix = mlx_get_data_addr(data->mlx,
		&data->sprites.ground.bits_per, &data->sprites.ground.line_len,
			&data->sprites.ground.endian);
	data->sprites.coin.image = mlx_xpm_file_to_image(data->mlx,
		"sprites/coin.xpm", &x, &y);
	data->sprites.coin.image_pix = mlx_get_data_addr(data->mlx,
		&data->sprites.coin.bits_per, &data->sprites.coin.line_len,
			&data->sprites.coin.endian);
	data->sprites.exit_close.image = mlx_xpm_file_to_image(data->mlx,
		"sprites/exit_close.xpm", &x, &y);
	data->sprites.exit_close.image_pix = mlx_get_data_addr(data->mlx,
		&data->sprites.exit_close.bits_per, &data->sprites.exit_close.line_len,
			&data->sprites.exit_close.endian);
}
	
void	init_image2(t_data *data)
{
	int	x = 0;
	int	y = 0;
	data->sprites.exit_open.image = mlx_xpm_file_to_image(data->mlx,
		"sprites/exit_open.xpm", &x, &y);
	data->sprites.exit_open.image_pix = mlx_get_data_addr(data->mlx,
		&data->sprites.exit_open.bits_per, &data->sprites.exit_open.line_len,
			&data->sprites.exit_open.endian);

	data->sprites.player_back.image = mlx_xpm_file_to_image(data->mlx,
		"sprites/player_back.xpm", &x, &y);
	data->sprites.player_back.image_pix = mlx_get_data_addr(data->mlx,
		&data->sprites.player_back.bits_per, &data->sprites.player_back.line_len,
			&data->sprites.player_back.endian);

	data->sprites.player_front.image = mlx_xpm_file_to_image(data->mlx,
		"sprites/player_front.xpm", &x, &y);
	data->sprites.player_front.image_pix = mlx_get_data_addr(data->mlx,
		&data->sprites.player_front.bits_per, &data->sprites.player_front.line_len,
			&data->sprites.player_front.endian);
			
	data->sprites.player_left.image = mlx_xpm_file_to_image(data->mlx,
		"sprites/player_left.xpm", &x, &y);
	data->sprites.player_left.image_pix = mlx_get_data_addr(data->mlx,
		&data->sprites.player_left.bits_per, &data->sprites.player_left.line_len,
			&data->sprites.player_left.endian);
}

void	init_image3(t_data *data)
{
	int	x = 0;
	int	y = 0;
	data->sprites.player_right.image = mlx_xpm_file_to_image(data->mlx,
		"sprites/player_right.xpm", &x, &y);
	data->sprites.player_right.image_pix = mlx_get_data_addr(data->mlx,
		&data->sprites.player_right.bits_per, &data->sprites.player_right.line_len,
			&data->sprites.player_right.endian);
}

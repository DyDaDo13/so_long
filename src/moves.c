/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylmarti <dylmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:04:36 by dylmarti          #+#    #+#             */
/*   Updated: 2023/12/04 19:56:32 by dylmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_up(t_data *data)
{
	data->y -= 32;
	data->p_y -= 1;
	mlx_put_image_to_window(data->mlx, data->win,
		data->sprites.player_back.image, data->x, data->y);
	mlx_put_image_to_window(data->mlx, data->win,
		data->sprites.ground.image, data->x, data->y + 32);
	mlx_put_image_to_window(data->mlx, data->win,
		data->sprites.exit_close.image, (data->e_x * 32), (data->e_y * 32));
	ft_printf("Moves = %i\n", data->moves += 1);
}

void	move_down(t_data *data)
{
	data->y += 32;
	data->p_y += 1;
	mlx_put_image_to_window(data->mlx, data->win,
		data->sprites.player_front.image, data->x, data->y);
	mlx_put_image_to_window(data->mlx, data->win,
		data->sprites.ground.image, data->x, data->y - 32);
	mlx_put_image_to_window(data->mlx, data->win,
		data->sprites.exit_close.image, (data->e_x * 32), (data->e_y * 32));
	ft_printf("Moves = %i\n", data->moves += 1);
}

void	move_left(t_data *data)
{
	data->x -= 32;
	data->p_x -= 1;
	mlx_put_image_to_window(data->mlx, data->win,
		data->sprites.player_left.image, data->x, data->y);
	mlx_put_image_to_window(data->mlx, data->win,
		data->sprites.ground.image, data->x + 32, data->y);
	mlx_put_image_to_window(data->mlx, data->win,
		data->sprites.exit_close.image, (data->e_x * 32), (data->e_y * 32));
	ft_printf("Moves = %i\n", data->moves += 1);
}

void	move_right(t_data *data)
{
	data->x += 32;
	data->p_x += 1;
	mlx_put_image_to_window(data->mlx, data->win,
		data->sprites.player_right.image, data->x, data->y);
	mlx_put_image_to_window(data->mlx, data->win,
		data->sprites.ground.image, data->x - 32, data->y);
	mlx_put_image_to_window(data->mlx, data->win,
		data->sprites.exit_close.image, (data->e_x * 32), (data->e_y * 32));
	ft_printf("Moves = %i\n", data->moves += 1);
}

void	end_game(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win,
		data->sprites.exit_open.image, (data->e_x * 32), (data->e_y * 32));
	data->map[data->e_y][data->e_x] = 'O';
}

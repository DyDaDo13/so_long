/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylmarti <dylmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:47:34 by dylmarti          #+#    #+#             */
/*   Updated: 2023/12/04 19:49:10 by dylmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_stop(t_data *data)
{
	destroy_all_images(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_all(data);
	exit(0);
	return (0);
}

int	ft_key_check(int key, t_data *data)
{
	data->x = data->p_x * 32;
	data->y = data->p_y * 32;
	if (key == XK_Escape || data->map[data->p_y][data->p_x] == 'O')
		ft_stop(data);
	if (data->y > 32 && data->map[data->p_y - 1][data->p_x] != '1' &&
		key == XK_w)
		move_up(data);
	if (data->y < ((data->map_height - 1) * 32)
		&& data->map[data->p_y + 1][data->p_x] != '1' && key == XK_s)
		move_down(data);
	if (data->x > 32 && data->map[data->p_y][data->p_x - 1] != '1' &&
		key == XK_a)
		move_left(data);
	if (data->x < (data->map_width * 32)
		&& data->map[data->p_y][data->p_x + 1] != '1' && key == XK_d)
		move_right(data);
	if (data->map[data->p_y][data->p_x] == 'C')
	{
		data->map[data->p_y][data->p_x] = '0';
		data->c_game += 1;
	}
	if (data->c == data->c_game)
		end_game(data);
	return (0);
}

void	draw_map(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		data->x = 0;
		while (data->map[i][j])
		{
			draw_images(data, i, j);
			j++;
			data->x += 32;
		}
		data->y += 32;
		i++;
	}
}

void	ft_display(t_data *data)
{
	data->x = 0;
	data->y = 0;
	data->c_game = 0;
	data->moves = 0;
	find_e(data->map, data);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, (data->map_width * 32),
			((data->map_height - 1) * 32), "Sekiro Shadow Die Once");
	init_images(data);
	init_image2(data);
	init_image3(data);
	draw_map(data);
	mlx_hook(data->win, 3, (1L << 0) + (1L << 1), ft_key_check, data);
	mlx_hook(data->win, 17, 0L, ft_stop, data);
	mlx_loop(data->mlx);
}

int	main(int ac, char **av)
{
	t_data	data;
	int		file;

	if (ac == 2 && ft_strcmp(av[1], ".ber") == 0)
	{
		file = open(av[1], O_RDONLY);
		if (file == -1)
			return (1);
		data.map = init_map(file, &data);
		if (is_map_valid(data.map, &data) == 1)
			return (free_all(&data), close(file), 1);
		ft_display(&data);
	}
	return (0);
}

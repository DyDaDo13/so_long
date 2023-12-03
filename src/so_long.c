/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:47:34 by dylmarti          #+#    #+#             */
/*   Updated: 2023/12/03 17:03:40 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_stop(t_data *data)
{
	mlx_destroy_image(data->mlx, data->images.sprites.coin);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);	
	return (0);
}

int	ft_key_check(int key, t_data *data)
{
	if (key == XK_Escape)
		ft_stop(data);
	if (data->y > 0)
	{
		data->y = data->y - 1;
		mlx_put_image_to_window(data->mlx, data->win, data->images.sprites.coin, data->x, data->y);
	}
	if (data->x > 0)
	{
		data->x = data->x - 1;
		mlx_put_image_to_window(data->mlx, data->win, data->images.sprites.coin, data->x, data->y);
	}
	if (data->y < 1080 - 100)
	{
		data->y = data->y + 1;
		mlx_put_image_to_window(data->mlx, data->win, data->images.sprites.coin, data->x, data->y);
	}
	if (data->x < 1920 - 500)
	{
		data->x = data->x + 1;
		mlx_put_image_to_window(data->mlx, data->win, data->images.sprites.coin, data->x, data->y);
	}
	mlx_put_image_to_window(data->mlx, data->win, data->images.sprites.coin, data->x, data->y);
	return (0);
}

void	init_images(t_data *data)
{
	int	x = 0;
	int	y = 0;
	
	data->images.sprites.coin = mlx_xpm_file_to_image(data->mlx, "coin.xpm", &x, &y);
	data->images.image_pix = mlx_get_data_addr(data->images.sprites.coin, &data->images.bits_per, &data->images.line_len, &data->images.endian);
}

void	draw_map()

void	ft_display(t_data *data)
{
	data->x = 0;
	data->y = 0;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1920, 1080, "so_long");
	init_images(data);
	mlx_put_image_to_window(data->mlx, data->win, data->images.sprites.coin, data->x, data->y);

	mlx_key_hook(data->win, ft_key_check, data);
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
		data.MAP = init_map(file, &data);
		if (is_map_valid(data.MAP, &data) == 1)
			return (free_all(data), close(file), 1);
		ft_display(&data);
		free_all(data);
		close(file);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylmarti <dylmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:47:34 by dylmarti          #+#    #+#             */
/*   Updated: 2023/12/04 17:30:07 by dylmarti         ###   ########.fr       */
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
	if (key == XK_Escape)
		ft_stop(data);
	if (data->y > 32 && data->MAP[data->p_y - 1][data->p_x] != '1' && key == XK_w) // haut
	{
		data->y -= 32;
		data->p_y -= 1;
		printf("y = %i\nx = %i\np_y = %i\np_x = %i\n\n", data->y, data->x, data->p_y, data->p_x);
		mlx_put_image_to_window(data->mlx, data->win, data->sprites.player_back.image, data->x, data->y);
		mlx_put_image_to_window(data->mlx, data->win, data->sprites.ground.image, data->x, data->y + 32);
	}
	if (data->y < ((data->map_height - 1) * 32) && data->MAP[data->p_y + 1][data->p_x] != '1' && key == XK_s) // bas
	{
		data->y += 32;
		data->p_y += 1;
		printf("y = %i\nx = %i\np_y = %i\np_x = %i\n\n", data->y, data->x, data->p_y, data->p_x);
		mlx_put_image_to_window(data->mlx, data->win, data->sprites.player_front.image, data->x, data->y);
		mlx_put_image_to_window(data->mlx, data->win, data->sprites.ground.image, data->x, data->y - 32);
	}
	if (data->x > 32 && data->MAP[data->p_y][data->p_x - 1] != '1' && key == XK_a) // gauche
	{
		data->x -= 32;
		data->p_x -= 1;
		printf("y = %i\nx = %i\np_y = %i\np_x = %i\n\n", data->y, data->x, data->p_y, data->p_x);
		mlx_put_image_to_window(data->mlx, data->win, data->sprites.player_left.image, data->x, data->y);
		mlx_put_image_to_window(data->mlx, data->win, data->sprites.ground.image, data->x + 32, data->y);
	}
	if (data->x < (data->map_width * 32) && data->MAP[data->p_y][data->p_x + 1] != '1' && key == XK_d) // droite
	{
		data->x += 32;
		data->p_x += 1;
		printf("y = %i\nx = %i\np_y = %i\np_x = %i\n\n", data->y, data->x, data->p_y, data->p_x);
		mlx_put_image_to_window(data->mlx, data->win, data->sprites.player_right.image, data->x, data->y);
		mlx_put_image_to_window(data->mlx, data->win, data->sprites.ground.image, data->x - 32, data->y);
	}
	//mlx_put_image_to_window(data->mlx, data->win, data->images.sprites.coin, data->x, data->y);
	return (0);
}

void	draw_map(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (data->MAP[i])
	{
		j = 0;
		data->x = 0;
		while (data->MAP[i][j])
		{
			if (data->MAP[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->win, data->sprites.walls.image, data->x, data->y);
			if (data->MAP[i][j] == '0')
				mlx_put_image_to_window(data->mlx, data->win, data->sprites.ground.image, data->x, data->y);
			if (data->MAP[i][j] == 'C')
				mlx_put_image_to_window(data->mlx, data->win, data->sprites.coin.image, data->x, data->y);
			if (data->MAP[i][j] == 'E')
				mlx_put_image_to_window(data->mlx, data->win, data->sprites.exit_close.image, data->x, data->y);
			if (data->MAP[i][j] == 'P')
				mlx_put_image_to_window(data->mlx, data->win, data->sprites.player_front.image, data->x, data->y);
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
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, (data->map_width * 32), ((data->map_height - 1) * 32), "so_long");
	init_images(data);
	init_image2(data);
	init_image3(data);

	draw_map(data);
	
	//mlx_put_image_to_window(data->mlx, data->win, data->images.sprites.coin, data->x, data->y);

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
			return (free_all(&data), close(file), 1);
		ft_display(&data);
	}
	return (0);
}

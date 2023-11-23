/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylmarti <dylmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:47:34 by dylmarti          #+#    #+#             */
/*   Updated: 2023/11/23 17:58:58 by dylmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_stop(t_data *data)
{
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
	return (0);
}

void	init_images(t_data *data)
{
	mlx_xpm_file_to_image(data->mlx, "caca.xpm", NULL, NULL);
}

void	ft_display(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1920, 1080, "so_long");
	
	mlx_key_hook(data->win, ft_key_check, data);
	mlx_hook(data->win, 17, 0L, ft_stop, data);
	

	mlx_loop(data->mlx);
}

int	main(void)
{
	t_data	data;
	
	ft_display(&data);
	
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:47:34 by dylmarti          #+#    #+#             */
/*   Updated: 2023/11/28 18:02:14 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_stop(t_data *data)
{
	mlx_destroy_image(data->mlx, data->caca.image);
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
	while (data->y > 0)
	{
		data->y = data->y - 1;
		mlx_put_image_to_window(data->mlx, data->win, data->caca.image, data->x, data->y);
	}
	while (data->x > 0)
	{
		data->x = data->x - 1;
		mlx_put_image_to_window(data->mlx, data->win, data->caca.image, data->x, data->y);
	}
	while (data->y < 1080 - 100)
	{
		data->y = data->y + 1;
		mlx_put_image_to_window(data->mlx, data->win, data->caca.image, data->x, data->y);
	}
	while (data->x < 1920 - 500)
	{
		data->x = data->x + 1;
		mlx_put_image_to_window(data->mlx, data->win, data->caca.image, data->x, data->y);
	}
	mlx_put_image_to_window(data->mlx, data->win, data->caca.image, data->x, data->y);
	return (0);
}

void	init_images(t_data *data)
{
	int	x = 0;
	int	y = 0;
	
	data->caca.image = mlx_xpm_file_to_image(data->mlx, "caca.xpm", &x, &y);
	data->caca.image_pix = mlx_get_data_addr(data->caca.image, &data->caca.bits_per, &data->caca.line_len, &data->caca.endian);
}

void	ft_display(t_data *data)
{
	data->x = 0;
	data->y = 0;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1920, 1080, "so_long");
	init_images(data);
	mlx_put_image_to_window(data->mlx, data->win, data->caca.image, data->x, data->y);

	mlx_key_hook(data->win, ft_key_check, data);
	mlx_hook(data->win, 17, 0L, ft_stop, data);
	

	mlx_loop(data->mlx);
}


char	*init_map(int file)
{
	char	*map;
	
	map = get_next_line(file);
	return (map);
}

int	line_len(int file)
{
	int		i;
	char	*str;

	i = 0;
	str = get_next_line(file);
	while (str != NULL)
	{
		i++;
		str = get_next_line(file);
	}
	return (i);
}

int	ft_maplen(char *str)
{
	int	i;
	
	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

int	is_wall_valid(int file)
{
	t_map *check;
	char *map;
	int		index;
	int		size;
	
	check = malloc(sizeof(t_map));
	check->player = 0;
	check->collectables = 0;
	check->exit = 0;
	
	index = 0;
	map = get_next_line(file);
	size = ft_maplen(map);
	printf("%s", map);
	while (map[index] != '\n')
	{
		if (map[index] != '1')
			return (1);
		index++;
	}
	index = 0;
	map = get_next_line(file);
	printf("%s", map);
	if (map[0] == '1' && map[ft_maplen(map) - 1] == '1' && ft_maplen(map) == size)
	{
		while (map[index] != '\n')
		{
			if (map[index] == 'P')
				check->player += 1;
			if (map[index] == 'C')
				check->collectables += 1;
			if (map[index] == 'E')
				check->exit += 1;
			index++;
		}
	}
	else
		return (1);
	index = 0;
	map = get_next_line(file);
	printf("%s", map);
	if (map[0] == '1' && map[ft_maplen(map) - 1] == '1' && ft_maplen(map) == size)
	{
		while (map[index] != '\n')
		{
			if (map[index] == 'P')
				check->player += 1;
			else if (map[index] == 'C')
				check->collectables += 1;
			else if (map[index] == 'E')
				check->exit += 1;
			else
				return (1);
			index++;
		}
	}
	else
		return (1);
	index = 0;
	map = get_next_line(file);
	printf("%s", map);
	if (map[0] == '1' && map[ft_maplen(map) - 1] == '1' && ft_maplen(map) == size)
	{
		while (map[index] != '\n')
		{
			if (map[index] == 'P')
				check->player += 1;
			if (map[index] == 'C')
				check->collectables += 1;
			if (map[index] == 'E')
				check->exit += 1;
			index++;
		}
	}
	else
		return (1);
	index = 0;
	map = get_next_line(file);
	printf("%s\n", map);
	while (map[index] != '\0')
	{
		if (map[index] != '1')
			return (1);
		index++;
	}
	if (check->player != 1 || check->collectables < 1 || check->exit != 1)
		return (1);
	return (0);
}

int	is_map_valid(int file)
{
	if (is_wall_valid(file) == 1)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	//t_data	data;
	int		file;
	//char	*map;

	if (ac == 2)
	{
		file = open(av[1], O_RDONLY);
		// printf("%s", get_next_line(file));
		// return (0);
		if (is_map_valid(file) == 0)
		{
			printf("good");
		}
		else
			printf("bad");
		// map = init_map(file);
		// printf("%s", map);
		// map = init_map(file);
		// printf("%s", map);
		// map = init_map(file);
		// printf("%s", map);
		// map = init_map(file);
		// printf("%s", map);
		// map = init_map(file);
		// printf("%s", map);
		// map = init_map(file);
		// printf("%s", map);
		// map = init_map(file);
		// printf("%s", map);
		//ft_display(&data);
	}
	return (0);
}

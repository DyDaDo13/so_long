/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:32:54 by dylmarti          #+#    #+#             */
/*   Updated: 2023/11/28 15:49:05 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>
# include <sys/mman.h>
# include <X11/Xlib.h>
# include <X11/Xutil.h>
# include <sys/ipc.h>
# include <sys/shm.h>
# include <X11/extensions/XShm.h>
# include <X11/XKBlib.h>
typedef struct	s_image
{
	void	*image;
	char	*image_pix;
	int		bits_per;
	int		endian;
	int		line_len;
}t_image;

typedef struct s_map
{
	int		player;
	int		exit;
	int		collectables;
}t_map;

typedef struct	s_data
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	t_map	map;
	t_image	caca;
}t_data;

#endif

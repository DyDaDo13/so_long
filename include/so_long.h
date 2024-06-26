/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylmarti <dylmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:32:54 by dylmarti          #+#    #+#             */
/*   Updated: 2023/12/04 19:47:41 by dylmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "get_next_line.h"
# include "ft_printf.h"
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

typedef struct s_map
{
	char			*map_line;
	struct s_map	*next;
}	t_map;

typedef struct s_image
{
	void	*image;
	char	*image_pix;
	int		bits_per;
	int		endian;
	int		line_len;
}	t_image;

typedef struct s_sprites
{
	t_image	coin;
	t_image	walls;
	t_image	ground;
	t_image	exit_open;
	t_image	exit_close;
	t_image	player_left;
	t_image	player_right;
	t_image	player_front;
	t_image	player_back;
}	t_sprites;

typedef struct s_point
{
	int		x;
	int		y;
	int		c;
	int		e;
}t_point;

typedef struct s_data
{
	char			**map;
	void			*mlx;
	void			*win;
	int				c_game;
	int				moves;
	int				p;
	int				c;
	int				e;
	int				x;
	int				y;
	int				e_x;
	int				e_y;
	int				p_x;
	int				p_y;
	int				map_height;
	int				map_width;
	t_map			*map_char;
	t_sprites		sprites;
}t_data;

void	ft_lstadd_back(t_map **lst, t_map *new);
t_map	*ft_lstlast(t_map *lst);
t_map	*ft_lstnew(void *content);
void	ft_lstdelone(t_map *lst, void (*del)(void*));
int		ft_lstsize(t_map *lst);
char	**init_map(int fd, t_data *data);
size_t	ft_strlen(char *s);
int		ft_printf(const char *format, ...);
void	free_map(t_data *data);
void	free_list(t_map **map);
void	free_all(t_data *data);
int		is_map_valid(char **map, t_data *data);
void	find_p(char **map, t_point *P, t_data *data);
void	find_e(char **map, t_data *data);
void	flood_fill(char **tab, t_point *size, t_point *begin, t_data *data);
int		ft_strcmp(char *str, char *to_find);
void	init_images(t_data *data);
void	init_image2(t_data *data);
void	init_image3(t_data *data);
void	destroy_all_images(t_data *data);
char	**map_dup(char **tab, t_data *data);
void	move_up(t_data *data);
void	move_down(t_data *data);
void	move_left(t_data *data);
void	move_right(t_data *data);
void	end_game(t_data *data);
void	draw_images(t_data *data, int i, int j);

#endif

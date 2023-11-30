/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:32:54 by dylmarti          #+#    #+#             */
/*   Updated: 2023/11/30 21:05:23 by dydado13         ###   ########.fr       */
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

typedef struct s_map
{
	char			*map_line;
	int				P;
	int				E;
	int				C;
	int				map_height;
	int				map_width;
	struct	s_map	*next;
}t_map;

typedef struct s_image
{
	void	*image;
	char	*image_pix;
	int		bits_per;
	int		endian;
	int		line_len;
}t_image;


typedef struct s_data
{
	char	**MAP;
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	t_map	*map;
	t_image	caca;
}t_data;

void	ft_lstadd_back(t_map **lst, t_map *new);
t_map	*ft_lstlast(t_map *lst);
t_map	*ft_lstnew(void *content);
void	ft_lstdelone(t_map *lst, void (*del)(void*));
int	ft_lstsize(t_map *lst);
char	**init_map(int fd, t_data data);

#endif

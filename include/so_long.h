/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dliu <dliu@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/06 12:14:25 by dliu          #+#    #+#                 */
/*   Updated: 2023/02/08 12:49:36 by dliu          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <string.h>
# include <stdio.h>
# include <math.h>
# include "libft.h"
# include "MLX42.h"
//# include "../../../mlx/minilibx-linux/mlx.h"
//# include "../../../mlx/minilibx-mms/mlx.h"
# define WIN_WIDTH 1024
# define WIN_HEIGHT 720

typedef struct s_pos
{
	size_t	x;
	size_t	y;
}				t_pos;

typedef struct s_img
{
	void	*image;
	void	*addr;
	int		bpp;
	int		len;
	int		endian;
}			t_img;

typedef struct s_player
{
	t_pos	pos;
	t_img	sprite_up;
	t_img	sprite_left;
	t_img	sprite_right;
	t_img	sprite_down;
}			t_player;

typedef struct s_collect
{
	t_pos	pos;
	t_img	sprite;
	int		got;
}			t_collect;

typedef struct s_gate
{
	t_pos	pos;
	t_img	sprite;
	int		open;
}			t_gate;

typedef struct s_data
{
	char		**map;
	size_t		size_x;
	size_t		size_y;
	size_t		moves;
	size_t		score;
	size_t		total;
	t_collect	**collects;
	t_player	player;
	t_gate		gate;
}			t_data;

typedef struct s_prog
{
	void	*mlx;
	void	*window;
	t_img	*img;
	t_data	*data;
}			t_prog;

void	map_create(char *filename, t_data *data);
void	map_elements(t_data *data);
void	map_path(t_data *data);
void	draw_map(t_data *data);
void	game_start(t_data *data);
void	terminate(t_data *data, char *what, char *why);

#endif
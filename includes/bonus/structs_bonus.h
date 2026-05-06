/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 14:18:20 by aghergut          #+#    #+#             */
/*   Updated: 2026/05/06 16:39:04 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_BONUS_H
# define STRUCTS_BONUS_H

# include "macros_bonus.h"

typedef struct s_mapxy
{
	int	x;
	int	y;
}	t_mapxy;

typedef struct s_bfs_state
{
	int	*q_x;
	int	*q_y;
	int	head;
	int	tail;
	int	room_id;
}	t_bfs_state;

typedef struct s_fill_ctx
{
	char	**map;
	t_mapxy	*dim;
	int		*sx;
	int		*sy;
	int		top;
}	t_fill_ctx;

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	pln_x;
	double	pln_y;
	int		pitch;
	int		moves;
}	t_player;

typedef struct s_texture
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		line_len;
	int		endian;
}	t_texture;

typedef enum e_shotgun_state
{
	SHOTGUN_IDLE,
	SHOTGUN_SHOOTING,
	SHOTGUN_RELOADING,
	SHOTGUN_OUT_OF_AMMO
}	t_shotgun_state;

typedef struct s_shotgun
{
	t_shotgun_state	state;
	int				ammo;
	int				animation_frame;
	int				animation_timer;
}	t_shotgun;

typedef struct s_door
{
	int		map_x;
	int		map_y;
	int		is_open;
	double	animation_progress;
	int		opened_at_frame;
}	t_door;

typedef struct s_ray
{
	double	camera_x;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	wall_x;
	int		tex_x;
}	t_ray;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_image;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			win_width;
	int			win_height;
	t_image		frame;
	t_player	player;
	t_texture	tex_wall_dark[5];
	t_texture	tex_floor;
	t_texture	tex_shotgun[15];
	t_texture	tex_door[4];
	t_shotgun	shotgun;
	t_door		doors[MAX_DOORS];
	int			door_count;
	char		**original_map;
	char		**map;
	int			map_width;
	int			map_height;
	double		*z_buffer;
	int			frame_count;
	int			key_w;
	int			key_s;
	int			key_a;
	int			key_d;
	int			key_left;
	int			key_right;
	int			mouse_x;
	int			mouse_y;
	int			mouse_init;
	double		delta_time;
	long long	last_frame_us;
	int			floor_color;
	int			ceiling_color;
	int			has_floor_color;
	int			has_ceiling_color;
	char		*tex_no_path;
	char		*tex_so_path;
	char		*tex_we_path;
	char		*tex_ea_path;
}	t_game;

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 15:49:02 by vruiz-ru          #+#    #+#             */
/*   Updated: 2026/05/06 15:05:16 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "macros.h"

typedef struct s_mapxy
{
	int	x;
	int	y;
}	t_mapxy;

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

typedef struct s_ray
{
	double	cam_x;
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

// Graphics/Window System
typedef struct s_mlx_context
{
	void	*mlx;
	void	*win;
	int		win_width;
	int		win_height;
	t_image	frame;
}	t_mlx_context;

// World Geometry
typedef struct s_map_data
{
	char	**map;
	int		map_width;
	int		map_height;
}	t_map_data;

// Texture Assets
typedef struct s_assets
{
	t_texture	tex_wall[4];
	t_texture	tex_weapon;
	char		*tex_no_path;
	char		*tex_so_path;
	char		*tex_we_path;
	char		*tex_ea_path;
}	t_assets;

// Input Management
typedef struct s_input
{
	int	key_w;
	int	key_s;
	int	key_a;
	int	key_d;
	int	key_left;
	int	key_right;
}	t_input;

// Frame Timing
typedef struct s_timing
{
	double		delta_t;
	long long	lframe_us;
	int			frame_count;
}	t_timing;

// Rendering Configuration
typedef struct s_render_config
{
	int	floor_color;
	int	ceiling_color;
	int	has_floor_color;
	int	has_ceiling_color;
}	t_render_config;

// Main Game State (Refactored)
typedef struct s_game
{
	t_mlx_context	graph;
	t_map_data		map;
	t_assets		assets;
	t_player		kid;
	t_input			input;
	t_timing		cron;
	t_render_config	render;
	bool			is_pressed;
}	t_game;

#endif

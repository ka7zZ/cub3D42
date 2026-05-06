/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 15:48:13 by vruiz-ru          #+#    #+#             */
/*   Updated: 2026/05/06 14:22:01 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../../import/mlx/mlx.h"
# include "../../import/libft/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdbool.h>
# include <time.h>

# include "macros.h"
# include "structs.h"

void		ft_raycast_frame(t_game *game);
void		ft_init_ray(t_ray *ray, t_game *game, int x);
void		ft_perform_dda(t_ray *ray, t_game *game);
void		ft_calculate_wall_height(t_ray *ray, t_game *game);
void		ft_draw_wall_column(t_game *game, t_ray *ray, int x);
t_texture	*ft_select_texture(t_game *game, t_ray *ray);

void		ft_put_pixel(t_image *img, int x, int y, int color);
int			ft_get_texture_color(t_texture *tex, int x, int y);
void		ft_draw_floor_ceiling_textured(t_game *game);
void		ft_draw_crosshair(t_game *game);
void		ft_draw_weapon_hud(t_game *game);

void		ft_move_forward(t_game *game);
void		ft_move_backward(t_game *game);
void		ft_move_left(t_game *game);
void		ft_move_right(t_game *game);
void		ft_update_player(t_game *game);

int			ft_init_stage_map_window(t_game *game, char *map_file);
int			ft_init_stage_assets_world(t_game *game);
void		ft_init_stage_runtime(t_game *game);
int			ft_game_loop(t_game *game);
int			ft_check_wall(t_game *game, double x, double y);

int			ft_mouse_pressed(int button, int x, int y, t_game *game);
int			ft_mouse_released(int button, int x, int y, t_game *game);
int			ft_key_press(int keycode, t_game *game);
int			ft_key_release(int keycode, t_game *game);
int			ft_close_game(t_game *game);
int			ft_focus_out(t_game *game);
int			ft_focus_in(t_game *game);

int			ft_parse_map(t_game *game, char *filename);
void		ft_find_player_spawn(t_game *game);
void		ft_floodfill(char **map, t_mapxy *point, int x, int y);

int			ft_load_textures(t_game *game);
void		ft_free_textures(t_game *game);
int			ft_load_texture(t_game *game, t_texture *tex, char *path);
int			ft_load_wall_textures(t_game *g);
int			ft_load_floor_textures(t_game *g);
void		ft_free_dual_wall_textures(t_game *g);

int			ft_init_game(t_game *game, char *map_file);
void		ft_init_mlx(t_game *game);
void		ft_free_game(t_game *game);
void		ft_exit_error(t_game *game, char *msg);
void		ft_print_controls(void);

int			ft_parse_config_line(t_game *game, char *line);
int			ft_read_cub_lines(t_game *game, char *filename);
int			ft_finalize_map_shape(t_game *game);
int			ft_validate_chars_and_spawn(t_game *game);
int			ft_validate_map(t_game *game);

#endif

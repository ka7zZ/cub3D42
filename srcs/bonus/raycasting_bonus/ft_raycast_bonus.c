/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-ru <vruiz-ru@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 14:19:39 by aghergut          #+#    #+#             */
/*   Updated: 2026/05/06 20:08:51 by vruiz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/bonus/cub3d_bonus.h"

static void	ft_draw_column(t_game *game, t_ray *ray, int x)
{
	t_ray	behind_ray;

	if (ft_is_door_cell(game, ray))
	{
		behind_ray = *ray;
		ft_continue_dda_after_door(&behind_ray, game);
		if (behind_ray.map_x >= 0 && behind_ray.map_x < game->map.map_width
			&& behind_ray.map_y >= 0 && behind_ray.map_y < game->map.map_height)
		{
			ft_calculate_wall_height(&behind_ray, game);
			ft_draw_wall_column(game, &behind_ray, x);
		}
	}
	ft_calculate_wall_height(ray, game);
	game->z_buffer[x] = ray->perp_wall_dist;
	ft_draw_wall_column(game, ray, x);
}

static void	ft_draw_columns_loop(t_game *game, int *x, int win_width)
{
	t_ray	ray;
	t_ray	ray_copy;

	ft_init_ray(&ray, game, *x);
	ft_perform_dda(&ray, game);
	ft_draw_column(game, &ray, *x);
	if (RAYCAST_COLUMN_STEP == 2 && *x + 1 < win_width)
	{
		ray_copy = ray;
		ft_draw_column(game, &ray_copy, *x + 1);
	}
	*x += RAYCAST_COLUMN_STEP;
}

static void	ft_draw_columns(t_game *game)
{
	int		x;
	int		win_width;

	win_width = game->graph.win_width;
	x = 0;
	while (x < win_width - 2)
	{
		ft_draw_columns_loop(game, &x, win_width);
		if (x < win_width)
			ft_draw_columns_loop(game, &x, win_width);
	}
	while (x < win_width)
		ft_draw_columns_loop(game, &x, win_width);
}

void	ft_raycast_frame(t_game *game)
{
	ft_draw_floor_ceiling_textured(game);
	ft_draw_columns(game);
	ft_draw_shotgun_hud(game);
	ft_draw_crosshair(game);
	ft_draw_radar(game);
	mlx_put_image_to_window(game->graph.mlx, game->graph.win,
		game->graph.frame.img, 0, 0);
}

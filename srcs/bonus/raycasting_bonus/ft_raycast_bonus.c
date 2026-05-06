/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 14:19:39 by aghergut          #+#    #+#             */
/*   Updated: 2026/05/06 16:26:53 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/bonus/cub3d_bonus.h"

static int	ft_door_blocks_ray(t_game *game, t_ray *ray)
{
	int	i;

	i = 0;
	while (i < game->door_count)
	{
		if (game->doors[i].map_x == ray->map_x
			&& game->doors[i].map_y == ray->map_y)
			return (!game->doors[i].is_open);
		i++;
	}
	return (0);
}

void	ft_perform_dda(t_ray *ray, t_game *game)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map_x < 0 || ray->map_x >= game->map.map_width
			|| ray->map_y < 0 || ray->map_y >= game->map.map_height)
			ray->hit = 1;
		else if (game->map.map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
		else if (game->map.map[ray->map_y][ray->map_x] == 'D')
			ray->hit = ft_door_blocks_ray(game, ray);
	}
}

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

static void	ft_draw_columns(t_game *game)
{
	t_ray	ray;
	t_ray	ray_copy;
	int		x;
	int		win_width;

	win_width = game->graph.win_width;
	x = 0;
	while (x < win_width - 2)
	{
		ft_init_ray(&ray, game, x);
		ft_perform_dda(&ray, game);
		ft_draw_column(game, &ray, x);
		if (RAYCAST_COLUMN_STEP == 2 && x + 1 < win_width)
		{
			ray_copy = ray;
			ft_draw_column(game, &ray_copy, x + 1);
		}
		x += RAYCAST_COLUMN_STEP;
		if (x < win_width)
		{
			ft_init_ray(&ray, game, x);
			ft_perform_dda(&ray, game);
			ft_draw_column(game, &ray, x);
			if (RAYCAST_COLUMN_STEP == 2 && x + 1 < win_width)
			{
				ray_copy = ray;
				ft_draw_column(game, &ray_copy, x + 1);
			}
			x += RAYCAST_COLUMN_STEP;
		}
	}
	while (x < win_width)
	{
		ft_init_ray(&ray, game, x);
		ft_perform_dda(&ray, game);
		ft_draw_column(game, &ray, x);
		if (RAYCAST_COLUMN_STEP == 2 && x + 1 < win_width)
		{
			ray_copy = ray;
			ft_draw_column(game, &ray_copy, x + 1);
		}
		x += RAYCAST_COLUMN_STEP;
	}
	return ;
}

void	ft_raycast_frame(t_game *game)
{
	ft_draw_floor_ceiling_textured(game);
	ft_draw_columns(game);
	ft_draw_shotgun_hud(game);
	ft_draw_crosshair(game);
	ft_draw_radar(game);
	mlx_put_image_to_window(game->graph.mlx, game->graph.win, game->graph.frame.img, 0, 0);
}

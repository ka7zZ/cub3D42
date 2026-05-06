/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast_calc_utils_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-ru <vruiz-ru@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 14:19:44 by aghergut          #+#    #+#             */
/*   Updated: 2026/05/06 19:51:24 by vruiz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/bonus/cub3d_bonus.h"

static void	ft_set_ray_steps(t_ray *ray, t_game *game)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (game->kid.pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - game->kid.pos_x)
			* ray->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (game->kid.pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - game->kid.pos_y)
			* ray->delta_dist_y;
	}
}

static void	ft_calc_delta_dist(t_ray *ray)
{
	double	inv_dir_x;
	double	inv_dir_y;

	if (ray->dir_x == 0)
		ray->delta_dist_x = 1e30;
	else
	{
		inv_dir_x = 1.0 / ray->dir_x;
		if (inv_dir_x < 0)
			ray->delta_dist_x = -inv_dir_x;
		else
			ray->delta_dist_x = inv_dir_x;
	}
	if (ray->dir_y == 0)
		ray->delta_dist_y = 1e30;
	else
	{
		inv_dir_y = 1.0 / ray->dir_y;
		if (inv_dir_y < 0)
			ray->delta_dist_y = -inv_dir_y;
		else
			ray->delta_dist_y = inv_dir_y;
	}
}

void	ft_init_ray(t_ray *ray, t_game *game, int x)
{
	ray->camera_x = x * (2.0 / game->graph.win_width) - 1;
	ray->dir_x = game->kid.dir_x + game->kid.pln_x * ray->camera_x;
	ray->dir_y = game->kid.dir_y + game->kid.pln_y * ray->camera_x;
	ray->map_x = (int)game->kid.pos_x;
	ray->map_y = (int)game->kid.pos_y;
	ft_calc_delta_dist(ray);
	ray->hit = 0;
	ft_set_ray_steps(ray, game);
}

void	ft_calculate_wall_height(t_ray *ray, t_game *game)
{
	int	half_height;

	half_height = game->graph.win_height / 2;
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - game->kid.pos_x + (1 - ray->step_x)
				/ 2) / ray->dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - game->kid.pos_y + (1 - ray->step_y)
				/ 2) / ray->dir_y;
	if (ray->perp_wall_dist < 0.01)
		ray->perp_wall_dist = 0.01;
	ray->line_height = (int)(game->graph.win_height / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + half_height;
	ray->draw_start += game->kid.pitch;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + half_height;
	ray->draw_end += game->kid.pitch;
	if (ray->draw_end >= game->graph.win_height)
		ray->draw_end = game->graph.win_height - 1;
	if (ray->side == 0)
		ray->wall_x = game->kid.pos_y + ray->perp_wall_dist * ray->dir_y;
	else
		ray->wall_x = game->kid.pos_x + ray->perp_wall_dist * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);
}

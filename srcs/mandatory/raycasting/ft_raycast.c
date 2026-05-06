/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 17:29:30 by vruiz-ru          #+#    #+#             */
/*   Updated: 2026/05/06 18:40:25 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/mandatory/cub3d.h"

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
	}
}

static void	ft_copy_column(t_game *game, int from_x, int to_x, int llen)
{
	int		y;
	char	*src;
	char	*dst;
	int		offset;

	offset = game->graph.frame.bpp / 8;
	src = game->graph.frame.addr + from_x * offset;
	dst = game->graph.frame.addr + to_x * offset;
	y = 0;
	while (y < game->graph.win_height - 3)
	{
		*(unsigned int *)(dst + y * llen) = *(unsigned int *)(src + y * llen);
		offset = (y + 1) * llen;
		*(unsigned int *)(dst + offset) = *(unsigned int *)(src + offset);
		offset = (y + 2) * llen;
		*(unsigned int *)(dst + offset) = *(unsigned int *)(src + offset);
		offset = (y + 3) * llen;
		*(unsigned int *)(dst + offset) = *(unsigned int *)(src + offset);
		y += 4;
	}
	while (y < game->graph.win_height)
	{
		*(unsigned int *)(dst + y * llen) = *(unsigned int *)(src + y * llen);
		y++;
	}
}

static void	ft_process_ray(t_game *game, int x)
{
	t_ray	ray;

	ft_init_ray(&ray, game, x);
	ft_perform_dda(&ray, game);
	ft_calculate_wall_height(&ray, game);
	ft_draw_wall_column(game, &ray, x);
	if (RAYCAST_COLUMN_STEP == 2 && x + 1 < game->graph.win_width)
		ft_copy_column(game, x, x + 1, game->graph.frame.line_len);
}

void	ft_raycast_frame(t_game *game)
{
	int	x;
	int	win_width;

	win_width = game->graph.win_width;
	ft_draw_floor_ceiling_textured(game);
	x = 0;
	while (x < win_width - 2)
	{
		ft_process_ray(game, x);
		x += RAYCAST_COLUMN_STEP;
		if (x < win_width)
		{
			ft_process_ray(game, x);
			x += RAYCAST_COLUMN_STEP;
		}
	}
	while (x < win_width)
	{
		ft_process_ray(game, x);
		x += RAYCAST_COLUMN_STEP;
	}
	ft_draw_weapon_hud(game);
	ft_draw_crosshair(game);
	mlx_put_image_to_window(game->graph.mlx, game->graph.win,
		game->graph.frame.img, 0, 0);
}

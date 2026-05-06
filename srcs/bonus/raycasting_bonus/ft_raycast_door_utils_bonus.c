/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast_door_utils_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 14:19:55 by aghergut          #+#    #+#             */
/*   Updated: 2026/05/06 14:19:56 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/bonus/cub3d_bonus.h"

int	ft_is_door_cell(t_game *game, t_ray *ray)
{
	if (ray->map_x < 0 || ray->map_x >= game->map_width
		|| ray->map_y < 0 || ray->map_y >= game->map_height)
		return (0);
	return (game->map[ray->map_y][ray->map_x] == 'D');
}

void	ft_continue_dda_after_door(t_ray *ray, t_game *game)
{
	ray->hit = 0;
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
		if (ray->map_x < 0 || ray->map_x >= game->map_width
			|| ray->map_y < 0 || ray->map_y >= game->map_height)
		{
			ray->hit = 1;
			break ;
		}
		if (game->map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
}

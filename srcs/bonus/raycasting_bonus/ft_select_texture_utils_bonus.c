/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_texture_utils_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 14:20:22 by aghergut          #+#    #+#             */
/*   Updated: 2026/05/06 14:20:24 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/bonus/cub3d_bonus.h"

static t_texture	*ft_select_door_texture(t_game *game, t_ray *ray)
{
	int	i;
	int	frame;

	i = 0;
	while (i < game->door_count)
	{
		if (game->doors[i].map_x == ray->map_x
			&& game->doors[i].map_y == ray->map_y)
		{
			frame = (int)(game->doors[i].animation_progress * 3.99);
			if (frame < 0)
				frame = 0;
			if (frame > 3)
				frame = 3;
			return (&game->tex_door[frame]);
		}
		i++;
	}
	return (&game->tex_door[0]);
}

static t_texture	*ft_select_oriented_wall(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->dir_x > 0)
			return (&game->tex_wall_dark[3]);
		return (&game->tex_wall_dark[2]);
	}
	if (ray->dir_y > 0)
		return (&game->tex_wall_dark[0]);
	return (&game->tex_wall_dark[1]);
}

t_texture	*ft_select_texture(t_game *game, t_ray *ray)
{
	if (ray->map_y < 0 || ray->map_y >= game->map_height)
		return (&game->tex_wall_dark[0]);
	if (ray->map_x < 0 || ray->map_x >= game->map_width)
		return (&game->tex_wall_dark[0]);
	if (game->map[ray->map_y][ray->map_x] == 'D')
		return (ft_select_door_texture(game, ray));
	if (game->map[ray->map_y][ray->map_x] != '1')
		return (&game->tex_wall_dark[0]);
	return (ft_select_oriented_wall(game, ray));
}

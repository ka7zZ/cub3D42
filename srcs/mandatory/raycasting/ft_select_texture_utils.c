/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_texture_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 14:17:20 by aghergut          #+#    #+#             */
/*   Updated: 2026/05/06 14:17:21 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/mandatory/cub3d.h"

static t_texture	*ft_select_oriented_wall(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->dir_x > 0)
			return (&game->assets.tex_wall[3]);
		return (&game->assets.tex_wall[2]);
	}
	if (ray->dir_y > 0)
		return (&game->assets.tex_wall[0]);
	return (&game->assets.tex_wall[1]);
}

t_texture	*ft_select_texture(t_game *game, t_ray *ray)
{
	if (ray->map_y < 0 || ray->map_y >= game->map.map_height)
		return (&game->assets.tex_wall[0]);
	if (ray->map_x < 0 || ray->map_x >= game->map.map_width)
		return (&game->assets.tex_wall[0]);
	if (game->map.map[ray->map_y][ray->map_x] != '1')
		return (&game->assets.tex_wall[0]);
	return (ft_select_oriented_wall(game, ray));
}

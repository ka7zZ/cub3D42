/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-ru <vruiz-ru@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 20:34:36 by vruiz-ru          #+#    #+#             */
/*   Updated: 2026/05/05 20:34:39 by vruiz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/bonus/cub3d_bonus.h"

void	ft_init_doors(t_game *game)
{
	int	y;
	int	x;

	game->door_count = 0;
	y = 0;
	while (y < game->map.map_height)
	{
		x = 0;
		while (x < game->map.map_width)
		{
			if (game->map.map[y][x] == 'D' && game->door_count < MAX_DOORS)
			{
				game->doors[game->door_count].map_x = x;
				game->doors[game->door_count].map_y = y;
				game->doors[game->door_count].is_open = 0;
				game->doors[game->door_count].animation_progress = 0.0;
				game->doors[game->door_count].opened_at_frame = 0;
				game->door_count++;
			}
			x++;
		}
		y++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 14:15:26 by aghergut          #+#    #+#             */
/*   Updated: 2026/05/06 14:15:29 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/mandatory/cub3d.h"

static void	ft_apply_direction(t_game *g,
	double dir_x, double dir_y, t_vector plane)
{
	g->player.dir_x = dir_x;
	g->player.dir_y = dir_y;
	g->player.plane_x = plane.x;
	g->player.plane_y = plane.y;
}

void	ft_set_player_direction(t_game *game, char direction)
{
	t_vector	plane;

	if (direction == 'S')
	{
		plane.x = -0.66;
		plane.y = 0.0;
		return (ft_apply_direction(game, 0.0, 1.0, plane), (void)0);
	}
	if (direction == 'N')
	{
		plane.x = 0.66;
		plane.y = 0.0;
		return (ft_apply_direction(game, 0.0, -1.0, plane), (void)0);
	}
	if (direction == 'E')
	{
		plane.x = 0.0;
		plane.y = 0.66;
		return (ft_apply_direction(game, 1.0, 0.0, plane), (void)0);
	}
	plane.x = 0.0;
	plane.y = -0.66;
	ft_apply_direction(game, -1.0, 0.0, plane);
}

void	ft_find_player_spawn(t_game *game)
{
	int		y;
	int		x;
	char	spawn;

	y = 0;
	while (y < game->map.map_height)
	{
		x = 0;
		while (x < game->map.map_width)
		{
			spawn = game->map.map[y][x];
			if (spawn == 'N' || spawn == 'S' || spawn == 'E' || spawn == 'W')
			{
				game->player.pos_x = x + 0.5;
				game->player.pos_y = y + 0.5;
				ft_set_player_direction(game, spawn);
				game->map.map[y][x] = '0';
				return ;
			}
			x++;
		}
		y++;
	}
}

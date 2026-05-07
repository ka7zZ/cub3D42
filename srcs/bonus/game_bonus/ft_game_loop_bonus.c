/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_loop_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 20:34:45 by vruiz-ru          #+#    #+#             */
/*   Updated: 2026/05/07 13:37:23 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/bonus/cub3d_bonus.h"

static long long	ft_now_us(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((long long)tv.tv_sec * 1000000LL + (long long)tv.tv_usec);
}

static void	ft_update_delta_time(t_game *game)
{
	long long	now;

	now = ft_now_us();
	if (game->cron.last_frame_us == 0)
		game->cron.delta_time = 0.016;
	else
		game->cron.delta_time = (double)(now - game->cron.last_frame_us)
			/ 1000000.0;
	if (game->cron.delta_time < MIN_DELTA_TIME)
		game->cron.delta_time = MIN_DELTA_TIME;
	if (game->cron.delta_time > MAX_DELTA_TIME)
		game->cron.delta_time = MAX_DELTA_TIME;
	game->cron.last_frame_us = now;
}

static int	ft_cell_blocks_player(t_game *game, int map_x, int map_y)
{
	int	i;

	if (map_x < 0 || map_x >= game->map.map_width || map_y < 0
		|| map_y >= game->map.map_height)
		return (1);
	if (game->map.map[map_y][map_x] == '1')
		return (1);
	if (game->map.map[map_y][map_x] != 'D')
		return (0);
	i = 0;
	while (i < game->door_count)
	{
		if (game->doors[i].map_x == map_x && game->doors[i].map_y == map_y
			&& !game->doors[i].is_open)
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_wall(t_game *game, double x, double y)
{
	int	ix;
	int	iy;
	int	m[2];

	iy = -1;
	while (iy <= 1)
	{
		ix = -1;
		while (ix <= 1)
		{
			m[0] = (int)(x + ix * PLAYER_RADIUS);
			m[1] = (int)(y + iy * PLAYER_RADIUS);
			if (ft_cell_blocks_player(game, m[0], m[1]))
				return (1);
			ix++;
		}
		iy++;
	}
	return (0);
}

int	ft_game_loop(t_game *game)
{
	long long	frame_start;

	frame_start = ft_now_us();
	ft_update_delta_time(game);
	game->cron.frame_count++;
	ft_update_doors(game);
	ft_update_player(game);
	ft_update_shotgun(game);
	ft_raycast_frame(game);
	return (0);
}

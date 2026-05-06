/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 17:28:35 by vruiz-ru          #+#    #+#             */
/*   Updated: 2026/05/06 15:05:12 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/mandatory/cub3d.h"
#include <sys/time.h>

static long long	ft_now_us(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((long long)tv.tv_sec * 1000000LL + (long long)tv.tv_usec);
}

static int	ft_update_delta_time(t_game *game)
{
	long long	now;

	now = ft_now_us();
	if (game->cron.lframe_us == 0)
		game->cron.delta_t = 0.016;
	else
		game->cron.delta_t = (double)(now - game->cron.lframe_us) / 1000000.0;
	if (game->cron.delta_t < MIN_DELTA_TIME)
		game->cron.delta_t = MIN_DELTA_TIME;
	if (game->cron.delta_t > MAX_DELTA_TIME)
		game->cron.delta_t = MAX_DELTA_TIME;
	game->cron.lframe_us = now;
	return (0);
}

int	ft_check_wall(t_game *game, double x, double y)
{
	int		ix;
	int		iy;
	int		m[2];
	int		map_w;
	int		map_h;
	char	**map;

	map_w = game->map.map_width;
	map_h = game->map.map_height;
	map = game->map.map;
	iy = -1;
	while (iy <= 1)
	{
		ix = -1;
		while (ix <= 1)
		{
			if (ix == 0 && iy == 0)
			{
				ix++;
				continue ;
			}
			m[0] = (int)(x + ix * PLAYER_RADIUS);
			m[1] = (int)(y + iy * PLAYER_RADIUS);
			if (m[0] < 0 || m[0] >= map_w || m[1] < 0 || m[1] >= map_h)
				return (1);
			if (map[m[1]][m[0]] == '1')
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
	long long	delta_calc_time;
	long long	player_update_time;
	long long	raycast_time;
	long long	total_time;
	
	if (game->is_pressed == false) 
	{
		frame_start = ft_now_us();
	
		ft_update_delta_time(game);
		delta_calc_time = ft_now_us() - frame_start;
		
		game->cron.frame_count++;
		ft_update_player(game);
		player_update_time = ft_now_us() - frame_start - delta_calc_time;
		
		ft_raycast_frame(game);
		raycast_time = ft_now_us() - frame_start - delta_calc_time - player_update_time;
		
		total_time = ft_now_us() - frame_start;
	}
	return (0);
}

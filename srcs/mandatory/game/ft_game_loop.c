/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 17:28:35 by vruiz-ru          #+#    #+#             */
/*   Updated: 2026/05/07 19:51:46 by aghergut         ###   ########.fr       */
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
	int		i[2];
	int		mx;
	int		my;

	i[0] = -1;
	while (i[0] <= 1)
	{
		i[1] = -1;
		while (i[1] <= 1)
		{
			if (i[0] != 0 || i[1] != 0)
			{
				mx = (int)(x + i[1] * PLAYER_RADIUS);
				my = (int)(y + i[0] * PLAYER_RADIUS);
				if (mx < 0 || mx >= game->map.map_width
					|| my < 0 || my >= game->map.map_height)
					return (1);
				if (game->map.map[my][mx] == '1')
					return (1);
			}
			i[1]++;
		}
		i[0]++;
	}
	return (0);
}

int	ft_game_loop(t_game *game)
{
	if (game->is_pressed == true)
		return (0);
	ft_update_delta_time(game);
	game->cron.frame_count++;
	ft_update_player(game);
	ft_raycast_frame(game);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radar_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-ru <vruiz-ru@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 17:45:12 by vruiz-ru          #+#    #+#             */
/*   Updated: 2026/05/05 17:47:22 by vruiz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/bonus/cub3d_bonus.h"

static int	ft_min_int(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

static int	ft_radar_size(t_game *game, int padding)
{
	int	max_size;
	int	radar_size;

	max_size = ft_min_int(game->graph.win_width - 2 * padding,
			game->graph.win_height - 2 * padding);
	radar_size = (max_size * 30) / 100;
	if (radar_size < 150)
		radar_size = 150;
	if (radar_size > max_size)
		radar_size = max_size;
	return (radar_size);
}

void	ft_draw_radar(t_game *game)
{
	int	radar_size;
	int	radar_x;
	int	radar_y;
	int	padding;

	padding = 20;
	radar_size = ft_radar_size(game, padding);
	radar_x = game->graph.win_width - radar_size - padding;
	radar_y = padding;
	ft_draw_radar_map(game, radar_x, radar_y, radar_size);
	ft_draw_player_on_radar(game, radar_x, radar_y, radar_size);
	ft_draw_direction_on_radar(game, radar_x, radar_y, radar_size);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radar_draw_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 17:36:03 by vruiz-ru          #+#    #+#             */
/*   Updated: 2026/05/06 16:36:43 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/bonus/cub3d_bonus.h"

static int	ft_cell_size(t_game *game, int radar_size)
{
	int	cell_w;
	int	cell_h;

	if (game->map_width <= 0 || game->map_height <= 0)
		return (1);
	cell_w = radar_size / game->map_width;
	cell_h = radar_size / game->map_height;
	if (cell_w < cell_h)
		return (cell_w);
	return (cell_h);
}

static void	ft_player_pixel_pos(t_game *game, int radar[3], int p[2])
{
	int	off[2];

	off[0] = (radar[2] - game->map_width * radar[0]) / 2;
	off[1] = (radar[2] - game->map_height * radar[0]) / 2;
	if (off[0] < 0)
		off[0] = 0;
	if (off[1] < 0)
		off[1] = 0;
	p[0] = radar[1] + off[0] + (int)(game->kid.pos_x * radar[0]);
	p[1] = radar[3] + off[1] + (int)((game->map_height - game->kid.pos_y) * radar[0]);
}

void	ft_draw_player_on_radar(t_game *game, int radar_x, int radar_y,
		int radar_size)
{
	int	radar[4];
	int	p[2];
	int	i[2];

	radar[0] = ft_cell_size(game, radar_size);
	radar[1] = radar_x;
	radar[2] = radar_size;
	radar[3] = radar_y;
	ft_player_pixel_pos(game, radar, p);
	i[0] = -2;
	while (i[0] <= 2)
	{
		i[1] = -2;
		while (i[1] <= 2)
		{
			if (i[0] * i[0] + i[1] * i[1] <= 4)
				ft_put_radar_pixel(game, p[0] + i[1], p[1] + i[0], 0xFF0000);
			i[1]++;
		}
		i[0]++;
	}
}

void	ft_draw_direction_on_radar(t_game *game, int radar_x, int radar_y,
		int radar_size)
{
	int	radar[4];
	int	p[2];
	int	step;
	int	d[2];

	radar[0] = ft_cell_size(game, radar_size);
	radar[1] = radar_x;
	radar[2] = radar_size;
	radar[3] = radar_y;
	ft_player_pixel_pos(game, radar, p);
	step = 1;
	while (step <= 8)
	{
		d[0] = p[0] + (int)(game->kid.dir_x * step * (radar[0] / 2.0));
		d[1] = p[1] - (int)(game->kid.dir_y * step * (radar[0] / 2.0));
		ft_put_radar_pixel(game, d[0], d[1], 0xFF6644);
		ft_put_radar_pixel(game, d[0] + 1, d[1], 0xFF6644);
		ft_put_radar_pixel(game, d[0], d[1] + 1, 0xFF6644);
		step++;
	}
}

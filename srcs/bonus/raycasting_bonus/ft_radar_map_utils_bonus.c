/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radar_map_utils_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-ru <vruiz-ru@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 14:19:33 by aghergut          #+#    #+#             */
/*   Updated: 2026/05/06 19:46:58 by vruiz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/bonus/cub3d_bonus.h"

static int	ft_cell_size(t_game *game, int radar_size)
{
	int	cell_w;
	int	cell_h;

	if (game->map.map_width <= 0 || game->map.map_height <= 0)
		return (1);
	cell_w = radar_size / game->map.map_width;
	cell_h = radar_size / game->map.map_height;
	if (cell_w < cell_h)
		return (cell_w);
	return (cell_h);
}

static int	ft_cell_color(char tile)
{
	if (tile == '1')
		return (0x00AA00);
	if (tile == 'D')
		return (0x00FF00);
	return (0x001100);
}

static void	ft_draw_cell(t_game *game, int pos[2], int size, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ft_put_radar_pixel(game, pos[0] + j, pos[1] + i, color);
			j++;
		}
		i++;
	}
}

static void	ft_draw_cells_loop(t_game *game, int cell, int off[2], int radar[2])
{
	int	m[2];
	int	p[2];

	m[1] = 0;
	while (m[1] < game->map.map_height)
	{
		m[0] = 0;
		while (m[0] < game->map.map_width)
		{
			p[0] = radar[0] + off[0] + m[0] * cell;
			p[1] = radar[1] + off[1] + (game->map.map_height - 1 - m[1]) * cell;
			ft_draw_cell(game, p, cell,
				ft_cell_color(game->map.map[m[1]][m[0]]));
			m[0]++;
		}
		m[1]++;
	}
}

void	ft_draw_radar_map(t_game *game, int radar_x, int radar_y,
		int radar_size)
{
	int	off[2];
	int	cell;
	int	radar[2];

	radar[0] = radar_x;
	radar[1] = radar_y;
	cell = ft_cell_size(game, radar_size);
	off[0] = (radar_size - game->map.map_width * cell) / 2;
	off[1] = (radar_size - game->map.map_height * cell) / 2;
	if (off[0] < 0)
		off[0] = 0;
	if (off[1] < 0)
		off[1] = 0;
	ft_draw_cells_loop(game, cell, off, radar);
}

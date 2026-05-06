/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hud_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 14:19:19 by aghergut          #+#    #+#             */
/*   Updated: 2026/05/06 14:19:20 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/bonus/cub3d_bonus.h"

static void	ft_draw_crosshair_h(t_game *game, int cx, int cy)
{
	int	i;

	i = 4;
	while (i <= 14)
	{
		ft_put_pixel(&game->graph.frame, cx + i, cy - 1, 0x000000);
		ft_put_pixel(&game->graph.frame, cx + i, cy + 1, 0x000000);
		ft_put_pixel(&game->graph.frame, cx - i, cy - 1, 0x000000);
		ft_put_pixel(&game->graph.frame, cx - i, cy + 1, 0x000000);
		ft_put_pixel(&game->graph.frame, cx + i, cy, 0xFFFFFF);
		ft_put_pixel(&game->graph.frame, cx - i, cy, 0xFFFFFF);
		i++;
	}
}

static void	ft_draw_crosshair_v(t_game *game, int cx, int cy)
{
	int	i;

	i = 4;
	while (i <= 14)
	{
		ft_put_pixel(&game->graph.frame, cx - 1, cy + i, 0x000000);
		ft_put_pixel(&game->graph.frame, cx + 1, cy + i, 0x000000);
		ft_put_pixel(&game->graph.frame, cx - 1, cy - i, 0x000000);
		ft_put_pixel(&game->graph.frame, cx + 1, cy - i, 0x000000);
		ft_put_pixel(&game->graph.frame, cx, cy + i, 0xFFFFFF);
		ft_put_pixel(&game->graph.frame, cx, cy - i, 0xFFFFFF);
		i++;
	}
}

void	ft_draw_crosshair(t_game *game)
{
	int	cx;
	int	cy;

	cx = game->graph.win_width / 2;
	cy = game->graph.win_height / 2;
	ft_draw_crosshair_h(game, cx, cy);
	ft_draw_crosshair_v(game, cx, cy);
	ft_put_pixel(&game->graph.frame, cx, cy, 0xFFFFFF);
}

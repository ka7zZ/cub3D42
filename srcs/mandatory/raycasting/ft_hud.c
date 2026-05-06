/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hud.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 14:16:37 by aghergut          #+#    #+#             */
/*   Updated: 2026/05/06 14:26:42 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/mandatory/cub3d.h"

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

static void	ft_draw_weapon_row(t_game *game, t_texture *tex, int y)
{
	int	x;
	int	tex_x;
	int	tex_y;
	int	color;

	x = 0;
	while (x < 400)
	{
		tex_x = (x * tex->width) / 400;
		tex_y = (y * tex->height) / 300;
		color = ft_get_texture_color(tex, tex_x, tex_y);
		if ((color & 0xFF000000) != 0xFF000000)
			ft_put_pixel(&game->graph.frame, game->graph.win_width / 2 - 200 + x + 80,
				game->graph.win_height - 300 + y, color);
		x++;
	}
}

void	ft_draw_weapon_hud(t_game *game)
{
	t_texture	*tex;
	int			y;

	tex = &game->assets.tex_weapon;
	if (!tex->img)
		return ;
	y = 0;
	while (y < 300)
	{
		ft_draw_weapon_row(game, tex, y);
		y++;
	}
}

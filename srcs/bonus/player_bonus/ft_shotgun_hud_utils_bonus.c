/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shotgun_hud_utils_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-ru <vruiz-ru@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 14:19:13 by aghergut          #+#    #+#             */
/*   Updated: 2026/05/06 19:39:42 by vruiz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/bonus/cub3d_bonus.h"

static int	ft_shotgun_tex_index(t_game *game)
{
	if (game->shotgun.state == SHOTGUN_SHOOTING)
	{
		if (game->shotgun.animation_frame < 15)
			return (game->shotgun.animation_frame);
		return (14);
	}
	if (game->shotgun.state == SHOTGUN_RELOADING)
	{
		if (game->shotgun.animation_frame <= 6)
			return (7 + game->shotgun.animation_frame);
		return (14);
	}
	if (game->shotgun.state == SHOTGUN_OUT_OF_AMMO)
		return (0);
	return (0);
}

static void	ft_draw_shotgun_row(t_game *game, t_texture *tex, int y)
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
			ft_put_pixel(&game->graph.frame, game->graph.win_width / 2 - 200 + x
				+ 80, game->graph.win_height - 300 + y, color);
		x++;
	}
}

void	ft_draw_shotgun_hud(t_game *game)
{
	t_texture	*tex;
	int			y;

	tex = &game->assets.tex_shotgun[ft_shotgun_tex_index(game)];
	if (!tex->img)
		return ;
	y = 0;
	while (y < 300)
		ft_draw_shotgun_row(game, tex, y++);
}

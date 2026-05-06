/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radar_color_utils_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-ru <vruiz-ru@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 14:19:27 by aghergut          #+#    #+#             */
/*   Updated: 2026/05/06 19:42:06 by vruiz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/bonus/cub3d_bonus.h"

int	ft_blend_color(int bg_color, int fg_color, double alpha)
{
	int	r;
	int	g;
	int	b;

	r = ((fg_color >> 16) & 0xFF) * alpha + ((bg_color >> 16) & 0xFF) * (1
			- alpha);
	g = ((fg_color >> 8) & 0xFF) * alpha + ((bg_color >> 8) & 0xFF) * (1
			- alpha);
	b = (fg_color & 0xFF) * alpha + (bg_color & 0xFF) * (1 - alpha);
	return ((r << 16) | (g << 8) | b);
}

int	ft_get_pixel_color(t_game *game, int x, int y)
{
	char	*pixel;

	if (x < 0 || x >= game->graph.win_width || y < 0
		|| y >= game->graph.win_height)
		return (0);
	pixel = game->graph.frame.addr + (y * game->graph.frame.line_len + x
			* (game->graph.frame.bpp / 8));
	return (*(unsigned int *)pixel);
}

void	ft_put_radar_pixel(t_game *game, int x, int y, int color)
{
	int	bg_color;
	int	blended_color;

	if (x < 0 || x >= game->graph.win_width || y < 0
		|| y >= game->graph.win_height)
		return ;
	bg_color = ft_get_pixel_color(game, x, y);
	blended_color = ft_blend_color(bg_color, color, 0.7);
	ft_put_pixel(&game->graph.frame, x, y, blended_color);
}

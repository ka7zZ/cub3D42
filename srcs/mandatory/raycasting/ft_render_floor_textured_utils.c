/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_floor_textured_utils.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 18:16:16 by vruiz-ru          #+#    #+#             */
/*   Updated: 2026/05/07 12:11:24 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/mandatory/cub3d.h"

static void	ft_fill_line(t_image *img, int y, int w, int color)
{
	int		x;
	char	*base;
	int		stride;
	int		pixel_size;

	pixel_size = img->bpp / 8;
	stride = img->line_len;
	base = img->addr + (y * stride);
	x = 0;
	while (x < w - 3)
	{
		*(unsigned int *)(base + x * pixel_size) = color;
		*(unsigned int *)(base + (x + 1) * pixel_size) = color;
		*(unsigned int *)(base + (x + 2) * pixel_size) = color;
		*(unsigned int *)(base + (x + 3) * pixel_size) = color;
		x += 4;
	}
	while (x < w)
	{
		*(unsigned int *)(base + x * pixel_size) = color;
		x++;
	}
}

static void	ft_fill_color(t_game *game, int *y, int plane, int color)
{
	int		win_width;

	win_width = game->graph.win_width;
	while (*y < plane - 3)
	{
		ft_fill_line(&game->graph.frame, *y, win_width, color);
		ft_fill_line(&game->graph.frame, *y + 1, win_width, color);
		ft_fill_line(&game->graph.frame, *y + 2, win_width, color);
		ft_fill_line(&game->graph.frame, *y + 3, win_width, color);
		*y += 4;
	}
	while (*y < plane)
	{
		ft_fill_line(&game->graph.frame, (*y)++, win_width, color);
	}
}

void	ft_draw_floor_ceiling_textured(t_game *game)
{
	int		horizon;
	int		y;
	int		win_height;

	win_height = game->graph.win_height;
	horizon = win_height / 2;
	if (horizon < 0)
		horizon = 0;
	if (horizon > win_height)
		horizon = win_height;
	y = 0;
	ft_fill_color(game, &y, horizon, game->render.ceiling_color);
	ft_fill_color(game, &y, win_height, game->render.floor_color);
}

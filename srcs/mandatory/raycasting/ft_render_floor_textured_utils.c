/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_floor_textured_utils.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 18:16:16 by vruiz-ru          #+#    #+#             */
/*   Updated: 2026/05/06 14:26:42 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/mandatory/cub3d.h"

static void	ft_fill_line_fast_unrolled(t_image *img, int y, int width, int color)
{
	int		x;
	char	*base;
	int		stride;
	int		pixel_size;

	pixel_size = img->bpp / 8;
	stride = img->line_len;
	base = img->addr + (y * stride);
	x = 0;
	while (x < width - 3)
	{
		*(unsigned int *)(base + x * pixel_size) = color;
		*(unsigned int *)(base + (x + 1) * pixel_size) = color;
		*(unsigned int *)(base + (x + 2) * pixel_size) = color;
		*(unsigned int *)(base + (x + 3) * pixel_size) = color;
		x += 4;
	}
	while (x < width)
	{
		*(unsigned int *)(base + x * pixel_size) = color;
		x++;
	}
}

void	ft_draw_floor_ceiling_textured(t_game *game)
{
	int		horizon;
	int		y;
	int		win_width;
	int		win_height;
	int		ceiling_color;
	int		floor_color;

	win_width = game->graph.win_width;
	win_height = game->graph.win_height;
	ceiling_color = game->render.ceiling_color;
	floor_color = game->render.floor_color;
	horizon = win_height / 2;
	if (horizon < 0)
		horizon = 0;
	if (horizon > win_height)
		horizon = win_height;
	y = 0;
	while (y < horizon - 3)
	{
		ft_fill_line_fast_unrolled(&game->graph.frame, y, win_width, ceiling_color);
		ft_fill_line_fast_unrolled(&game->graph.frame, y + 1, win_width, ceiling_color);
		ft_fill_line_fast_unrolled(&game->graph.frame, y + 2, win_width, ceiling_color);
		ft_fill_line_fast_unrolled(&game->graph.frame, y + 3, win_width, ceiling_color);
		y += 4;
	}
	while (y < horizon)
	{
		ft_fill_line_fast_unrolled(&game->graph.frame, y++, win_width, ceiling_color);
	}
	while (y < win_height - 3)
	{
		ft_fill_line_fast_unrolled(&game->graph.frame, y, win_width, floor_color);
		ft_fill_line_fast_unrolled(&game->graph.frame, y + 1, win_width, floor_color);
		ft_fill_line_fast_unrolled(&game->graph.frame, y + 2, win_width, floor_color);
		ft_fill_line_fast_unrolled(&game->graph.frame, y + 3, win_width, floor_color);
		y += 4;
	}
	while (y < win_height)
	{
		ft_fill_line_fast_unrolled(&game->graph.frame, y++, win_width, floor_color);
	}
}

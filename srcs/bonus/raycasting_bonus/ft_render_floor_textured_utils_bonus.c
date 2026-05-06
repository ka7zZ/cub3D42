/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_floor_textured_utils_bonus.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 14:19:59 by aghergut          #+#    #+#             */
/*   Updated: 2026/05/06 17:45:17 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/bonus/cub3d_bonus.h"

static void	ft_fill_line(t_image *img, int y, int width, int color)
{
	int		x;
	char	*base;
	int		pixel_size;

	pixel_size = img->bpp / 8;
	base = img->addr + (y * img->line_len);
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

	win_width = game->win_width;
	win_height = game->win_height;
	ceiling_color = game->ceiling_color;
	floor_color = game->floor_color;
	horizon = win_height / 2 + game->kid.pitch;
	if (horizon < 0)
		horizon = 0;
	if (horizon > win_height)
		horizon = win_height;
	y = 0;
	while (y < horizon - 3)
	{
		ft_fill_line(&game->frame, y, win_width, ceiling_color);
		ft_fill_line(&game->frame, y + 1, win_width, ceiling_color);
		ft_fill_line(&game->frame, y + 2, win_width, ceiling_color);
		ft_fill_line(&game->frame, y + 3, win_width, ceiling_color);
		y += 4;
	}
	while (y < horizon)
	{
		ft_fill_line(&game->frame, y++, win_width, ceiling_color);
	}
	while (y < win_height - 3)
	{
		ft_fill_line(&game->frame, y, win_width, floor_color);
		ft_fill_line(&game->frame, y + 1, win_width, floor_color);
		ft_fill_line(&game->frame, y + 2, win_width, floor_color);
		ft_fill_line(&game->frame, y + 3, win_width, floor_color);
		y += 4;
	}
	while (y < win_height)
	{
		ft_fill_line(&game->frame, y++, win_width, floor_color);
	}
}

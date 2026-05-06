/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_floor_textured_utils_bonus.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-ru <vruiz-ru@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 14:19:59 by aghergut          #+#    #+#             */
/*   Updated: 2026/05/06 19:51:17 by vruiz-ru         ###   ########.fr       */
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

static void	ft_draw_ceiling_loop(t_game *game, int *y, int horizon)
{
	while (*y < horizon - 3)
	{
		ft_fill_line(&game->graph.frame, *y,
			game->graph.win_width, game->render.ceiling_color);
		ft_fill_line(&game->graph.frame, *y + 1,
			game->graph.win_width, game->render.ceiling_color);
		ft_fill_line(&game->graph.frame, *y + 2,
			game->graph.win_width, game->render.ceiling_color);
		ft_fill_line(&game->graph.frame, *y + 3,
			game->graph.win_width, game->render.ceiling_color);
		*y += 4;
	}
	while (*y < horizon)
	{
		ft_fill_line(&game->graph.frame, (*y)++,
			game->graph.win_width, game->render.ceiling_color);
	}
}

static void	ft_draw_floor_loop(t_game *game, int *y)
{
	while (*y < game->graph.win_height - 3)
	{
		ft_fill_line(&game->graph.frame, *y,
			game->graph.win_width, game->render.floor_color);
		ft_fill_line(&game->graph.frame, *y + 1,
			game->graph.win_width, game->render.floor_color);
		ft_fill_line(&game->graph.frame, *y + 2,
			game->graph.win_width, game->render.floor_color);
		ft_fill_line(&game->graph.frame, *y + 3,
			game->graph.win_width, game->render.floor_color);
		*y += 4;
	}
	while (*y < game->graph.win_height)
	{
		ft_fill_line(&game->graph.frame, (*y)++,
			game->graph.win_width, game->render.floor_color);
	}
}

void	ft_draw_floor_ceiling_textured(t_game *game)
{
	int	horizon;
	int	y;

	horizon = game->graph.win_height / 2 + game->kid.pitch;
	if (horizon < 0)
		horizon = 0;
	if (horizon > game->graph.win_height)
		horizon = game->graph.win_height;
	y = 0;
	ft_draw_ceiling_loop(game, &y, horizon);
	ft_draw_floor_loop(game, &y);
}

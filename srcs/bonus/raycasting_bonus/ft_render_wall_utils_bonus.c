/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_wall_utils_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 14:20:17 by aghergut          #+#    #+#             */
/*   Updated: 2026/05/06 16:38:19 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/bonus/cub3d_bonus.h"

static void	ft_draw_wall_pixels_normal(t_game *g, t_ray *r, t_texture *tex, int x)
{
	double	step;
	double	pos;
	int		y;
	int		tex_y;
	int		color;
	char	*frame_addr;
	int		frame_line_len;
	int		x_offset;

	frame_addr = g->graph.frame.addr;
	frame_line_len = g->graph.frame.line_len;
	x_offset = x * (g->graph.frame.bpp / 8);
	step = 1.0 * tex->height / r->line_height;
	pos = (r->draw_start - g->graph.win_height / 2 - g->kid.pitch
			+ r->line_height / 2) * step;
	y = r->draw_start;
	while (y < r->draw_end)
	{
		tex_y = ((int)pos) & (tex->height - 1);
		color = ft_get_texture_color(tex, r->tex_x, tex_y);
		if (g->map.map[r->map_y][r->map_x] == 'D'
			&& (color & 0xFF000000) == 0xFF000000)
			color = -1;
		if (color != -1)
			*(unsigned int *)(frame_addr + x_offset + y * frame_line_len) = color;
		pos += step;
		y++;
	}
}

static void	ft_draw_wall_pixels_dark(t_game *g, t_ray *r, t_texture *tex, int x)
{
	double	step;
	double	pos;
	int		y;
	int		tex_y;
	int		color;
	char	*frame_addr;
	int		frame_line_len;
	int		x_offset;

	frame_addr = g->graph.frame.addr;
	frame_line_len = g->graph.frame.line_len;
	x_offset = x * (g->graph.frame.bpp / 8);
	step = 1.0 * tex->height / r->line_height;
	pos = (r->draw_start - g->graph.win_height / 2 - g->kid.pitch
			+ r->line_height / 2) * step;
	y = r->draw_start;
	while (y < r->draw_end)
	{
		tex_y = ((int)pos) & (tex->height - 1);
		color = ft_get_texture_color(tex, r->tex_x, tex_y);
		if (g->map.map[r->map_y][r->map_x] == 'D'
			&& (color & 0xFF000000) == 0xFF000000)
			color = -1;
		if (color != -1)
		{
			color = (color >> 1) & 8355711;
			*(unsigned int *)(frame_addr + x_offset + y * frame_line_len) = color;
		}
		pos += step;
		y++;
	}
}

void	ft_draw_wall_column(t_game *game, t_ray *ray, int x)
{
	t_texture	*tex;

	tex = ft_select_texture(game, ray);
	ray->tex_x = (int)(ray->wall_x * (double)tex->width);
	if ((ray->side == 0 && ray->dir_x > 0)
		|| (ray->side == 1 && ray->dir_y < 0))
		ray->tex_x = tex->width - ray->tex_x - 1;
	if (ray->side == 1)
		ft_draw_wall_pixels_dark(game, ray, tex, x);
	else
		ft_draw_wall_pixels_normal(game, ray, tex, x);
}

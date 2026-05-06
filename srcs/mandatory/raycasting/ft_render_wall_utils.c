/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_wall_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 14:17:12 by aghergut          #+#    #+#             */
/*   Updated: 2026/05/06 18:37:44 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/mandatory/cub3d.h"

static void	ft_put_px(t_game *g, int off, int y, int color)
{
	char	*addr;
	int		len;

	addr = g->graph.frame.addr;
	len = g->graph.frame.line_len;
	*(unsigned int *)(addr + off + y * len) = color;
}

static void	ft_draw_wall_px_on(t_game *g, t_ray *r, t_texture *tex, int x)
{
	double	step;
	double	pos;
	int		y;
	int		off;

	off = x * (g->graph.frame.bpp / 8);
	step = 1.0 * tex->height / r->line_height;
	pos = (r->draw_start - g->graph.win_height / 2.0
			+ r->line_height / 2.0) * step;
	y = r->draw_start;
	while (y < r->draw_end)
	{
		ft_put_px(g, off, y, ft_get_texture_color(tex, r->tex_x,
				((int)pos) & (tex->height - 1)));
		pos += step;
		y++;
	}
}

static void	ft_draw_wall_px_off(t_game *g, t_ray *r, t_texture *tex, int x)
{
	double	step;
	double	pos;
	int		y;
	int		off;

	off = x * (g->graph.frame.bpp / 8);
	step = 1.0 * tex->height / r->line_height;
	pos = (r->draw_start - g->graph.win_height / 2.0
			+ r->line_height / 2.0) * step;
	y = r->draw_start;
	while (y < r->draw_end)
	{
		ft_put_px(g, off, y, (ft_get_texture_color(tex, r->tex_x,
					((int)pos) & (tex->height - 1)) >> 1) & 8355711);
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
		ft_draw_wall_px_off(game, ray, tex, x);
	else
		ft_draw_wall_px_on(game, ray, tex, x);
}

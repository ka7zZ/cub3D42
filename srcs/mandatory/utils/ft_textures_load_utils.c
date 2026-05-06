/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures_load_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-ru <vruiz-ru@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 17:17:55 by vruiz-ru          #+#    #+#             */
/*   Updated: 2026/05/05 17:17:57 by vruiz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/mandatory/cub3d.h"

static int	ft_load_dark_walls(t_game *g)
{
	if (!ft_load_texture(g, &g->assets.tex_wall[0], g->assets.tex_no_path))
		return (0);
	if (!ft_load_texture(g, &g->assets.tex_wall[1], g->assets.tex_so_path))
		return (0);
	if (!ft_load_texture(g, &g->assets.tex_wall[2], g->assets.tex_we_path))
		return (0);
	if (!ft_load_texture(g, &g->assets.tex_wall[3], g->assets.tex_ea_path))
		return (0);
	return (1);
}

int	ft_load_wall_textures(t_game *g)
{
	return (ft_load_dark_walls(g));
}

int	ft_load_floor_textures(t_game *g)
{
	(void)g;
	return (1);
}

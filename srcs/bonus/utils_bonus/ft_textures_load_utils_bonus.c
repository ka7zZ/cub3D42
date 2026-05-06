/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures_load_utils_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 14:20:59 by aghergut          #+#    #+#             */
/*   Updated: 2026/05/06 14:21:00 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/bonus/cub3d_bonus.h"

static int	ft_load_dark_walls(t_game *g)
{
	if (!ft_load_texture(g, &g->tex_wall_dark[0], g->tex_no_path))
		return (0);
	if (!ft_load_texture(g, &g->tex_wall_dark[1], g->tex_so_path))
		return (0);
	if (!ft_load_texture(g, &g->tex_wall_dark[2], g->tex_we_path))
		return (0);
	if (!ft_load_texture(g, &g->tex_wall_dark[3], g->tex_ea_path))
		return (0);
	if (!ft_load_texture(g, &g->tex_wall_dark[4], g->tex_no_path))
		return (0);
	return (1);
}

int	ft_load_wall_textures(t_game *g)
{
	return (ft_load_dark_walls(g));
}

int	ft_load_floor_textures(t_game *g)
{
	return (ft_load_texture(g, &g->tex_floor, "assets/ingame/hall/floor.xpm"));
}

int	ft_load_gun_textures(t_game *g, char **gun_paths)
{
	int	i;

	i = 0;
	while (i < 15)
	{
		if (!ft_load_texture(g, &g->tex_shotgun[i], gun_paths[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_load_door_textures(t_game *g)
{
	if (!ft_load_texture(g, &g->tex_door[0], "assets/ingame/door/door1.xpm"))
		return (0);
	if (!ft_load_texture(g, &g->tex_door[1], "assets/ingame/door/door2.xpm"))
		return (0);
	if (!ft_load_texture(g, &g->tex_door[2], "assets/ingame/door/door3.xpm"))
		return (0);
	return (ft_load_texture(g, &g->tex_door[3],
			"assets/ingame/door/door4.xpm"));
}

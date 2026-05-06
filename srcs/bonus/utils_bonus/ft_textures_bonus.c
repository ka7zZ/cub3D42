/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 14:20:49 by aghergut          #+#    #+#             */
/*   Updated: 2026/05/06 14:20:50 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/bonus/cub3d_bonus.h"

static void	ft_init_gun_paths(char **gun_paths)
{
	gun_paths[0] = "assets/ingame/gun/(1)sgun_normal.xpm";
	gun_paths[1] = "assets/ingame/gun/(2)sgun_startshoot1.xpm";
	gun_paths[2] = "assets/ingame/gun/(3)sgun_startshoot2.xpm";
	gun_paths[3] = "assets/ingame/gun/(4)sgun_stopshoot1.xpm";
	gun_paths[4] = "assets/ingame/gun/(5)sgun_stopshoot2.xpm";
	gun_paths[5] = "assets/ingame/gun/(6)sgun_outbullets1.xpm";
	gun_paths[6] = "assets/ingame/gun/(7)sgun_outbullets2.xpm";
	gun_paths[7] = "assets/ingame/gun/(8)sgun_prepreload1.xpm";
	gun_paths[8] = "assets/ingame/gun/(9)sgun_prepreload2.xpm";
	gun_paths[9] = "assets/ingame/gun/(10)sgun_prepreload3.xpm";
	gun_paths[10] = "assets/ingame/gun/(11)sgun_startreload1.xpm";
	gun_paths[11] = "assets/ingame/gun/(12)sgun_startreload2.xpm";
	gun_paths[12] = "assets/ingame/gun/(13)sgun_endreload1.xpm";
	gun_paths[13] = "assets/ingame/gun/(14)sgun_endreload2.xpm";
	gun_paths[14] = "assets/ingame/gun/(15)sgun_endreload3.xpm";
}

int	ft_load_texture(t_game *game, t_texture *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(game->graph.mlx, path,
			&tex->width, &tex->height);
	if (!tex->img)
	{
		ft_putstr_fd("Error\nFailed to load texture: ", 2);
		if (path)
			ft_putstr_fd(path, 2);
		else
			ft_putstr_fd("(null)", 2);
		ft_putstr_fd("\n", 2);
		return (0);
	}
	tex->addr = mlx_get_data_addr(tex->img, &tex->bpp,
			&tex->line_len, &tex->endian);
	if (!tex->addr)
	{
		mlx_destroy_image(game->graph.mlx, tex->img);
		return (0);
	}
	return (1);
}

int	ft_load_textures(t_game *game)
{
	char	*gun_paths[15];

	ft_init_gun_paths(gun_paths);
	if (!ft_load_wall_textures(game))
		return (0);
	if (!ft_load_floor_textures(game))
		return (0);
	if (!ft_load_gun_textures(game, gun_paths))
		return (0);
	return (ft_load_door_textures(game));
}

void	ft_free_textures(t_game *game)
{
	ft_free_dual_wall_textures(game);
	if (game->assets.tex_floor.img)
		mlx_destroy_image(game->graph.mlx, game->assets.tex_floor.img);
	ft_free_array_textures(game, game->assets.tex_shotgun, 15);
	ft_free_array_textures(game, game->assets.tex_door, 4);
}

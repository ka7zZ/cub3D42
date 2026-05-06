/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game_utils_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 14:20:43 by aghergut          #+#    #+#             */
/*   Updated: 2026/05/06 14:20:44 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/bonus/cub3d_bonus.h"

int	ft_init_stage_map_window(t_game *game, char *map_file)
{
	if (!ft_parse_map(game, map_file))
		return (0);
	ft_init_mlx(game);
	return (1);
}

int	ft_init_stage_assets_world(t_game *game)
{
	if (!ft_load_textures(game))
		return (0);
	ft_init_doors(game);
	ft_init_shotgun(game);
	return (1);
}

void	ft_init_stage_runtime(t_game *game)
{
	mlx_mouse_hide(game->mlx, game->win);
	mlx_mouse_move(game->mlx, game->win, game->win_width / 2,
		game->win_height / 2);
	game->mouse_x = game->win_width / 2;
	game->mouse_y = game->win_height / 2;
	game->frame_count = 0;
	game->delta_time = 0.016;
	game->last_frame_us = 0;
}

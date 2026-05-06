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
	mlx_mouse_hide(game->graph.mlx, game->graph.win);
	mlx_mouse_move(game->graph.mlx, game->graph.win, game->graph.win_width / 2,
		game->graph.win_height / 2);
	game->input.mouse_x = game->graph.win_width / 2;
	game->input.mouse_y = game->graph.win_height / 2;
	game->cron.frame_count = 0;
	game->cron.delta_time = 0.016;
	game->cron.last_frame_us = 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-ru <vruiz-ru@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 15:54:50 by vruiz-ru          #+#    #+#             */
/*   Updated: 2026/05/05 15:55:05 by vruiz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/mandatory/cub3d.h"

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
	return (1);
}

void	ft_init_stage_runtime(t_game *game)
{
	game->timing.frame_count = 0;
	game->timing.delta_time = 0.016;
	game->timing.last_frame_us = 0;
}

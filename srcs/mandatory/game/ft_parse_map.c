/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-ru <vruiz-ru@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 15:55:33 by vruiz-ru          #+#    #+#             */
/*   Updated: 2026/05/05 15:58:48 by vruiz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/mandatory/cub3d.h"

static int	ft_has_required_config(t_game *game)
{
	if (!game->assets.tex_no_path || !game->assets.tex_so_path)
		return (0);
	if (!game->assets.tex_we_path || !game->assets.tex_ea_path)
		return (0);
	if (!game->render.has_floor_color || !game->render.has_ceiling_color)
		return (0);
	return (1);
}

int	ft_parse_map(t_game *game, char *filename)
{
	if (!ft_read_cub_lines(game, filename))
		return (ft_putstr_fd("Error\nInvalid .cub file\n", 2), 0);
	if (!ft_has_required_config(game))
		return (ft_putstr_fd("Error\nMissing config values\n", 2), 0);
	if (!ft_finalize_map_shape(game))
		return (ft_putstr_fd("Error\nInvalid map data\n", 2), 0);
	if (!ft_validate_chars_and_spawn(game))
		return (ft_putstr_fd("Error\nInvalid map characters/spawn\n", 2), 0);
	if (!ft_validate_map(game))
		return (ft_putstr_fd("Error\nMap is not closed\n", 2), 0);
	ft_find_player_spawn(game);
	return (1);
}

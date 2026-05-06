/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-ru <vruiz-ru@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 20:35:26 by vruiz-ru          #+#    #+#             */
/*   Updated: 2026/05/05 20:35:27 by vruiz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/bonus/cub3d_bonus.h"

int	ft_parse_config_line(t_game *game, char *line);
int	ft_read_cub_lines(t_game *game, char *filename);
int	ft_finalize_map_shape(t_game *game);
int	ft_validate_chars_and_spawn(t_game *game);
int	ft_validate_map(t_game *game);

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
	game->map.original_map = ft_mapdup(game->map.map);
	if (!game->map.original_map)
		return (0);
	ft_init_doors(game);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map_config_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-ru <vruiz-ru@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 20:35:36 by vruiz-ru          #+#    #+#             */
/*   Updated: 2026/05/05 20:35:38 by vruiz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/bonus/cub3d_bonus.h"

static int	ft_is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v'
		|| c == '\f');
}

static int	ft_parse_rgb(char *s, int *color)
{
	char	**parts;
	int		rgb[3];
	int		i;

	parts = ft_split(s, ',');
	if (!parts)
		return (0);
	i = 0;
	while (parts[i] && i < 3)
	{
		rgb[i] = ft_atoi(parts[i]);
		if (rgb[i] < 0 || rgb[i] > 255)
			return (ft_mapfree(&parts), 0);
		i++;
	}
	if (i != 3 || parts[3])
		return (ft_mapfree(&parts), 0);
	*color = (rgb[0] << 16) | (rgb[1] << 8) | rgb[2];
	return (ft_mapfree(&parts), 1);
}

static int	ft_parse_texture_id(t_game *game, char *trim)
{
	if (!ft_strncmp(trim, "NO", 2)
		&& ft_is_space(trim[2]) && !game->tex_no_path)
		return (game->tex_no_path = ft_strtrim(trim + 2, " \t"), 1);
	if (!ft_strncmp(trim, "SO", 2)
		&& ft_is_space(trim[2]) && !game->tex_so_path)
		return (game->tex_so_path = ft_strtrim(trim + 2, " \t"), 1);
	if (!ft_strncmp(trim, "WE", 2)
		&& ft_is_space(trim[2]) && !game->tex_we_path)
		return (game->tex_we_path = ft_strtrim(trim + 2, " \t"), 1);
	if (!ft_strncmp(trim, "EA", 2)
		&& ft_is_space(trim[2]) && !game->tex_ea_path)
		return (game->tex_ea_path = ft_strtrim(trim + 2, " \t"), 1);
	return (0);
}

static int	ft_parse_color_id(t_game *game, char *trim)
{
	if (trim[0] == 'F' && ft_is_space(trim[1]) && !game->has_floor_color)
	{
		if (!ft_parse_rgb(trim + 2, &game->floor_color))
			return (0);
		return (game->has_floor_color = 1, 1);
	}
	if (trim[0] == 'C' && ft_is_space(trim[1]) && !game->has_ceiling_color)
	{
		if (!ft_parse_rgb(trim + 2, &game->ceiling_color))
			return (0);
		return (game->has_ceiling_color = 1, 1);
	}
	return (0);
}

int	ft_parse_config_line(t_game *game, char *line)
{
	char	*trim;
	int		ok;

	trim = ft_strtrim(line, " \t\n\r\v\f");
	if (!trim)
		return (0);
	ok = ft_parse_texture_id(game, trim);
	if (!ok)
		ok = ft_parse_color_id(game, trim);
	free(trim);
	return (ok);
}

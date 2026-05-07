/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map_config.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 16:48:19 by vruiz-ru          #+#    #+#             */
/*   Updated: 2026/05/07 12:05:18 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/mandatory/cub3d.h"

static bool	ft_check_color(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		if (!ft_isdigit(str[idx]))
			return (false);
		idx++;
	}
	return (true);
}

static int	ft_parse_rgb(char *s, int *color)
{
	char	**parts;
	int		rgb[3];
	int		i;

	if (ft_ocurr(s, ',') != 2)
		return (0);
	parts = ft_split(s, ',');
	if (!parts)
		return (0);
	i = 0;
	while (parts[i] && i < 3)
	{
		if (!ft_check_color(parts[i]))
			return (ft_mapfree(&parts), 0);
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
	if (!ft_strncmp(trim, "NO", 2) && \
		ft_isspace(trim[2]) && !game->assets.tex_no_path)
		return (game->assets.tex_no_path = ft_strtrim(trim + 2, " \t"), 1);
	if (!ft_strncmp(trim, "SO", 2) && \
		ft_isspace(trim[2]) && !game->assets.tex_so_path)
		return (game->assets.tex_so_path = ft_strtrim(trim + 2, " \t"), 1);
	if (!ft_strncmp(trim, "WE", 2) && \
		ft_isspace(trim[2]) && !game->assets.tex_we_path)
		return (game->assets.tex_we_path = ft_strtrim(trim + 2, " \t"), 1);
	if (!ft_strncmp(trim, "EA", 2) && \
		ft_isspace(trim[2]) && !game->assets.tex_ea_path)
		return (game->assets.tex_ea_path = ft_strtrim(trim + 2, " \t"), 1);
	return (0);
}

static int	ft_parse_color_id(t_game *game, char *trim)
{
	if (trim[0] == 'F' && ft_isspace(trim[1]) && \
		!game->render.has_floor_color)
	{
		if (!ft_parse_rgb(trim + 2, &game->render.floor_color))
			return (0);
		return (game->render.has_floor_color = 1, 1);
	}
	if (trim[0] == 'C' && ft_isspace(trim[1]) && \
		!game->render.has_ceiling_color)
	{
		if (!ft_parse_rgb(trim + 2, &game->render.ceiling_color))
			return (0);
		return (game->render.has_ceiling_color = 1, 1);
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

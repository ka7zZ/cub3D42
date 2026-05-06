/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map_shape_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 14:18:42 by aghergut          #+#    #+#             */
/*   Updated: 2026/05/06 14:18:43 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/bonus/cub3d_bonus.h"

static int	ft_line_len_no_eol(char *line)
{
	int	len;

	len = (int)ft_strlen(line);
	while (len > 0 && (line[len - 1] == '\n' || line[len - 1] == '\r'))
		len--;
	return (len);
}

static int	ft_set_map_dimensions(t_game *game)
{
	int	y;
	int	len;

	game->map_height = (int)ft_mapsize(game->map);
	if (game->map_height <= 0)
		return (0);
	game->map_width = 0;
	y = 0;
	while (y < game->map_height)
	{
		len = ft_line_len_no_eol(game->map[y]);
		if (len > game->map_width)
			game->map_width = len;
		y++;
	}
	return (1);
}

static int	ft_alloc_norm_row(char **dst, int width, char *src)
{
	int	len;

	len = ft_line_len_no_eol(src);
	*dst = (char *)ft_calloc(width + 1, sizeof(char));
	if (!*dst)
		return (0);
	ft_memset(*dst, ' ', width);
	if (len > 0)
		ft_memcpy(*dst, src, len);
	return (1);
}

int	ft_finalize_map_shape(t_game *game)
{
	char	**norm;
	int		y;

	if (!ft_set_map_dimensions(game))
		return (0);
	norm = (char **)ft_calloc(game->map_height + 1, sizeof(char *));
	if (!norm)
		return (0);
	y = 0;
	while (y < game->map_height)
	{
		if (!ft_alloc_norm_row(&norm[y], game->map_width, game->map[y]))
			return (ft_mapfree(&norm), 0);
		y++;
	}
	ft_mapfree(&game->map);
	game->map = norm;
	return (1);
}

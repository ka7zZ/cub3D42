/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map_read.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 16:45:40 by vruiz-ru          #+#    #+#             */
/*   Updated: 2026/05/07 12:44:04 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/mandatory/cub3d.h"

int	ft_parse_config_line(t_game *game, char *line);

static int	ft_is_blank_line(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if (!ft_isspace(s[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	ft_store_map_line(t_game *game, char *line, int state[2])
{
	if (!state[0] && ft_is_blank_line(line))
		return (1);
	if (!state[0] && ft_parse_config_line(game, line))
		return (1);
	if (state[0] && ft_is_blank_line(line))
		return (state[1] = 1, 1);
	if (state[1])
		return (0);
	state[0] = 1;
	return (ft_mapitem_add(&game->map.map, line));
}

int	ft_read_cub_lines(t_game *game, char *filename)
{
	int		fd;
	char	*line;
	int		state[2];

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	state[0] = 0;
	state[1] = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (!ft_store_map_line(game, line, state))
			return (get_next_line_flush(fd), free(line), close(fd), 0);
		free(line);
		line = get_next_line(fd);
	}
	return (close(fd), 1);
}

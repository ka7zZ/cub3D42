/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map_validate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 14:16:19 by aghergut          #+#    #+#             */
/*   Updated: 2026/05/06 14:16:20 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/mandatory/cub3d.h"

int	ft_validate_chars_and_spawn(t_game *game)
{
	int	y;
	int	x;
	int	spawn_count;

	spawn_count = 0;
	y = 0;
	while (y < game->map.map_height)
	{
		x = 0;
		while (x < game->map.map_width)
		{
			if (!ft_strchr(" 01NSEW", game->map.map[y][x]))
				return (0);
			if (ft_strchr("NSEW", game->map.map[y][x]))
				spawn_count++;
			x++;
		}
		y++;
	}
	return (spawn_count == 1);
}

static int	ft_cell_touches_void(t_game *game, int y, int x)
{
	if (y == 0 || x == 0)
		return (1);
	if (y == game->map.map_height - 1 || x == game->map.map_width - 1)
		return (1);
	if (game->map.map[y - 1][x] == ' ' || game->map.map[y + 1][x] == ' ')
		return (1);
	if (game->map.map[y][x - 1] == ' ' || game->map.map[y][x + 1] == ' ')
		return (1);
	return (0);
}

int	ft_validate_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map.map_height)
	{
		x = 0;
		while (x < game->map.map_width)
		{
			if (ft_strchr("0NSEW", game->map.map[y][x])
				&& ft_cell_touches_void(game, y, x))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

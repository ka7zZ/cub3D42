/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_doors_utils_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 14:18:50 by aghergut          #+#    #+#             */
/*   Updated: 2026/05/06 14:18:52 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/bonus/cub3d_bonus.h"

static int	ft_player_on_door_cell(t_game *game, int door_idx)
{
	int	player_cell_x;
	int	player_cell_y;

	player_cell_x = (int)game->player.pos_x;
	player_cell_y = (int)game->player.pos_y;
	return (player_cell_x == game->doors[door_idx].map_x
		&& player_cell_y == game->doors[door_idx].map_y);
}

static void	ft_update_door_animation(t_game *game, int i, double target)
{
	double	delta;

	delta = target - game->doors[i].animation_progress;
	game->doors[i].animation_progress += delta * DOOR_ANIM_SMOOTH;
	if (game->doors[i].animation_progress > 1.0)
		game->doors[i].animation_progress = 1.0;
	if (game->doors[i].animation_progress < 0.0)
		game->doors[i].animation_progress = 0.0;
	if (game->doors[i].animation_progress > 0.995)
		game->doors[i].animation_progress = 1.0;
	if (game->doors[i].animation_progress < 0.005)
		game->doors[i].animation_progress = 0.0;
}

static void	ft_update_single_door(t_game *game, int i)
{
	int		frames_open;
	double	target;

	frames_open = game->frame_count - game->doors[i].opened_at_frame;
	if (game->doors[i].is_open && frames_open > DOOR_AUTO_CLOSE_FRAMES
		&& !ft_player_on_door_cell(game, i))
		game->doors[i].is_open = 0;
	if (game->doors[i].is_open)
		target = 1.0;
	else
		target = 0.0;
	ft_update_door_animation(game, i, target);
}

void	ft_update_doors(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->door_count)
	{
		ft_update_single_door(game, i);
		i++;
	}
}

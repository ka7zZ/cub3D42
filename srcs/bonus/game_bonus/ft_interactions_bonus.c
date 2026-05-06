/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interactions_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-ru <vruiz-ru@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 20:35:02 by vruiz-ru          #+#    #+#             */
/*   Updated: 2026/05/05 20:35:04 by vruiz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/bonus/cub3d_bonus.h"

static void	ft_print_door_state(int is_open)
{
	if (is_open)
		ft_printf("Door opened\n");
	else
		ft_printf("Door closed\n");
}

static int	ft_toggle_near_door(t_game *game)
{
	int		i;
	double	dx;
	double	dy;
	double	dist;

	i = 0;
	while (i < game->door_count)
	{
		dx = game->doors[i].map_x - game->player.pos_x;
		dy = game->doors[i].map_y - game->player.pos_y;
		dist = dx * dx + dy * dy;
		if (dist < INTERACT_RANGE * INTERACT_RANGE)
		{
			game->doors[i].is_open = !game->doors[i].is_open;
			if (game->doors[i].is_open)
				game->doors[i].opened_at_frame = game->frame_count;
			ft_print_door_state(game->doors[i].is_open);
			return (1);
		}
		i++;
	}
	return (0);
}

void	ft_handle_interaction(t_game *game)
{
	ft_toggle_near_door(game);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-ru <vruiz-ru@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 18:11:37 by vruiz-ru          #+#    #+#             */
/*   Updated: 2026/05/06 18:20:25 by vruiz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/mandatory/cub3d.h"

static void	ft_calc_new_pos(t_game *game, double *nx, double *ny, double step)
{
	if (game->input.key_w)
	{
		*nx += game->kid.dir_x * step;
		*ny += game->kid.dir_y * step;
	}
	if (game->input.key_s)
	{
		*nx -= game->kid.dir_x * step;
		*ny -= game->kid.dir_y * step;
	}
	if (game->input.key_a)
	{
		*nx -= game->kid.pln_x * step;
		*ny -= game->kid.pln_y * step;
	}
	if (game->input.key_d)
	{
		*nx += game->kid.pln_x * step;
		*ny += game->kid.pln_y * step;
	}
}

void	ft_move_player(t_game *game)
{
	double	new_x;
	double	new_y;
	double	step;

	step = MOVE_SPEED * game->cron.delta_t;
	new_x = game->kid.pos_x;
	new_y = game->kid.pos_y;
	ft_calc_new_pos(game, &new_x, &new_y, step);
	if (!ft_check_wall(game, new_x, game->kid.pos_y))
		game->kid.pos_x = new_x;
	if (!ft_check_wall(game, game->kid.pos_x, new_y))
		game->kid.pos_y = new_y;
}

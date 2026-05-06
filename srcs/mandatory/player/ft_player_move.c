/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-ru <vruiz-ru@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 18:11:37 by vruiz-ru          #+#    #+#             */
/*   Updated: 2026/05/05 18:11:38 by vruiz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/mandatory/cub3d.h"

void	ft_move_forward(t_game *game)
{
	double	new_x;
	double	new_y;
	double	step;

	step = MOVE_SPEED * game->timing.delta_time;
	new_x = game->player.pos_x + game->player.dir_x * step;
	new_y = game->player.pos_y + game->player.dir_y * step;
	if (!ft_check_wall(game, new_x, game->player.pos_y))
		game->player.pos_x = new_x;
	if (!ft_check_wall(game, game->player.pos_x, new_y))
		game->player.pos_y = new_y;
}

void	ft_move_backward(t_game *game)
{
	double	new_x;
	double	new_y;
	double	step;

	step = MOVE_SPEED * game->timing.delta_time;
	new_x = game->player.pos_x - game->player.dir_x * step;
	new_y = game->player.pos_y - game->player.dir_y * step;
	if (!ft_check_wall(game, new_x, game->player.pos_y))
		game->player.pos_x = new_x;
	if (!ft_check_wall(game, game->player.pos_x, new_y))
		game->player.pos_y = new_y;
}

void	ft_move_left(t_game *game)
{
	double	new_x;
	double	new_y;
	double	step;

	step = MOVE_SPEED * game->timing.delta_time;
	new_x = game->player.pos_x - game->player.plane_x * step;
	new_y = game->player.pos_y - game->player.plane_y * step;
	if (!ft_check_wall(game, new_x, game->player.pos_y))
		game->player.pos_x = new_x;
	if (!ft_check_wall(game, game->player.pos_x, new_y))
		game->player.pos_y = new_y;
}

void	ft_move_right(t_game *game)
{
	double	new_x;
	double	new_y;
	double	step;

	step = MOVE_SPEED * game->timing.delta_time;
	new_x = game->player.pos_x + game->player.plane_x * step;
	new_y = game->player.pos_y + game->player.plane_y * step;
	if (!ft_check_wall(game, new_x, game->player.pos_y))
		game->player.pos_x = new_x;
	if (!ft_check_wall(game, game->player.pos_x, new_y))
		game->player.pos_y = new_y;
}

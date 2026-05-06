/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_move_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 14:19:00 by aghergut          #+#    #+#             */
/*   Updated: 2026/05/06 14:19:01 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/bonus/cub3d_bonus.h"

void	ft_move_forward(t_game *game)
{
	double	new_x;
	double	new_y;
	double	step;

	step = MOVE_SPEED * game->delta_time;
	new_x = game->player.pos_x + game->player.dir_x * step;
	new_y = game->player.pos_y + game->player.dir_y * step;
	if (!ft_check_wall(game, new_x, game->player.pos_y))
	{
		game->player.pos_x = new_x;
		game->player.moves++;
	}
	if (!ft_check_wall(game, game->player.pos_x, new_y))
	{
		game->player.pos_y = new_y;
		game->player.moves++;
	}
}

void	ft_move_backward(t_game *game)
{
	double	new_x;
	double	new_y;
	double	step;

	step = MOVE_SPEED * game->delta_time;
	new_x = game->player.pos_x - game->player.dir_x * step;
	new_y = game->player.pos_y - game->player.dir_y * step;
	if (!ft_check_wall(game, new_x, game->player.pos_y))
	{
		game->player.pos_x = new_x;
		game->player.moves++;
	}
	if (!ft_check_wall(game, game->player.pos_x, new_y))
	{
		game->player.pos_y = new_y;
		game->player.moves++;
	}
}

void	ft_move_left(t_game *game)
{
	double	new_x;
	double	new_y;
	double	step;

	step = MOVE_SPEED * game->delta_time;
	new_x = game->player.pos_x - game->player.plane_x * step;
	new_y = game->player.pos_y - game->player.plane_y * step;
	if (!ft_check_wall(game, new_x, game->player.pos_y))
	{
		game->player.pos_x = new_x;
		game->player.moves++;
	}
	if (!ft_check_wall(game, game->player.pos_x, new_y))
	{
		game->player.pos_y = new_y;
		game->player.moves++;
	}
}

void	ft_move_right(t_game *game)
{
	double	new_x;
	double	new_y;
	double	step;

	step = MOVE_SPEED * game->delta_time;
	new_x = game->player.pos_x + game->player.plane_x * step;
	new_y = game->player.pos_y + game->player.plane_y * step;
	if (!ft_check_wall(game, new_x, game->player.pos_y))
	{
		game->player.pos_x = new_x;
		game->player.moves++;
	}
	if (!ft_check_wall(game, game->player.pos_x, new_y))
	{
		game->player.pos_y = new_y;
		game->player.moves++;
	}
}

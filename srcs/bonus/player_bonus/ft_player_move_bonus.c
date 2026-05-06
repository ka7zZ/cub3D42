/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_move_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 14:19:00 by aghergut          #+#    #+#             */
/*   Updated: 2026/05/06 16:39:04 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/bonus/cub3d_bonus.h"

void	ft_move_forward(t_game *game)
{
	double	new_x;
	double	new_y;
	double	step;

	step = MOVE_SPEED * game->delta_time;
	new_x = game->kid.pos_x + game->kid.dir_x * step;
	new_y = game->kid.pos_y + game->kid.dir_y * step;
	if (!ft_check_wall(game, new_x, game->kid.pos_y))
	{
		game->kid.pos_x = new_x;
		game->kid.moves++;
	}
	if (!ft_check_wall(game, game->kid.pos_x, new_y))
	{
		game->kid.pos_y = new_y;
		game->kid.moves++;
	}
}

void	ft_move_backward(t_game *game)
{
	double	new_x;
	double	new_y;
	double	step;

	step = MOVE_SPEED * game->delta_time;
	new_x = game->kid.pos_x - game->kid.dir_x * step;
	new_y = game->kid.pos_y - game->kid.dir_y * step;
	if (!ft_check_wall(game, new_x, game->kid.pos_y))
	{
		game->kid.pos_x = new_x;
		game->kid.moves++;
	}
	if (!ft_check_wall(game, game->kid.pos_x, new_y))
	{
		game->kid.pos_y = new_y;
		game->kid.moves++;
	}
}

void	ft_move_left(t_game *game)
{
	double	new_x;
	double	new_y;
	double	step;

	step = MOVE_SPEED * game->delta_time;
	new_x = game->kid.pos_x - game->kid.pln_x * step;
	new_y = game->kid.pos_y - game->kid.pln_y * step;
	if (!ft_check_wall(game, new_x, game->kid.pos_y))
	{
		game->kid.pos_x = new_x;
		game->kid.moves++;
	}
	if (!ft_check_wall(game, game->kid.pos_x, new_y))
	{
		game->kid.pos_y = new_y;
		game->kid.moves++;
	}
}

void	ft_move_right(t_game *game)
{
	double	new_x;
	double	new_y;
	double	step;

	step = MOVE_SPEED * game->delta_time;
	new_x = game->kid.pos_x + game->kid.pln_x * step;
	new_y = game->kid.pos_y + game->kid.pln_y * step;
	if (!ft_check_wall(game, new_x, game->kid.pos_y))
	{
		game->kid.pos_x = new_x;
		game->kid.moves++;
	}
	if (!ft_check_wall(game, game->kid.pos_x, new_y))
	{
		game->kid.pos_y = new_y;
		game->kid.moves++;
	}
}

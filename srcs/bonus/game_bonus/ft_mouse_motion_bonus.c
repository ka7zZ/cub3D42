/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_motion_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 20:35:19 by vruiz-ru          #+#    #+#             */
/*   Updated: 2026/05/06 16:39:04 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/bonus/cub3d_bonus.h"

static void	ft_apply_mouse_yaw(t_game *game, int delta_x)
{
	double	rot;
	double	old_dir_x;
	double	old_pln_x;

	if (!delta_x)
		return ;
	rot = -delta_x * MOUSE_YAW_SENS;
	old_dir_x = game->kid.dir_x;
	old_pln_x = game->kid.pln_x;
	game->kid.dir_x = old_dir_x * cos(rot)
		- game->kid.dir_y * sin(rot);
	game->kid.dir_y = old_dir_x * sin(rot)
		+ game->kid.dir_y * cos(rot);
	game->kid.pln_x = old_pln_x * cos(rot)
		- game->kid.pln_y * sin(rot);
	game->kid.pln_y = old_pln_x * sin(rot)
		+ game->kid.pln_y * cos(rot);
}

static void	ft_apply_mouse_pitch(t_game *game, int delta_y)
{
	if (delta_y)
		game->kid.pitch -= delta_y * MOUSE_PITCH_SENS;
	if (game->kid.pitch > game->graph.win_height / 2)
		game->kid.pitch = game->graph.win_height / 2;
	if (game->kid.pitch < -game->graph.win_height / 2)
		game->kid.pitch = -game->graph.win_height / 2;
}

static int	ft_clamp_delta(int value)
{
	if (value > 100)
		return (100);
	if (value < -100)
		return (-100);
	return (value);
}

int	ft_mouse_motion(int x, int y, t_game *game)
{
	int	delta_x;
	int	delta_y;

	if (!game->input.mouse_init)
	{
		game->input.mouse_x = x;
		game->input.mouse_y = y;
		game->input.mouse_init = 1;
		return (0);
	}
	delta_x = ft_clamp_delta(x - game->input.mouse_x);
	delta_y = ft_clamp_delta(y - game->input.mouse_y);
	game->input.mouse_x = x;
	game->input.mouse_y = y;
	ft_apply_mouse_yaw(game, delta_x);
	ft_apply_mouse_pitch(game, delta_y);
	if (delta_x || delta_y)
	{
		mlx_mouse_move(game->graph.mlx, game->graph.win, game->graph.win_width / 2,
			game->graph.win_height / 2);
		game->input.mouse_x = game->graph.win_width / 2;
		game->input.mouse_y = game->graph.win_height / 2;
	}
	return (0);
}

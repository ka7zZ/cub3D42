/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_motion_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-ru <vruiz-ru@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 20:35:19 by vruiz-ru          #+#    #+#             */
/*   Updated: 2026/05/05 20:35:21 by vruiz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/bonus/cub3d_bonus.h"

static void	ft_apply_mouse_yaw(t_game *game, int delta_x)
{
	double	rot;
	double	old_dir_x;
	double	old_plane_x;

	if (!delta_x)
		return ;
	rot = -delta_x * MOUSE_YAW_SENS;
	old_dir_x = game->player.dir_x;
	old_plane_x = game->player.plane_x;
	game->player.dir_x = old_dir_x * cos(rot)
		- game->player.dir_y * sin(rot);
	game->player.dir_y = old_dir_x * sin(rot)
		+ game->player.dir_y * cos(rot);
	game->player.plane_x = old_plane_x * cos(rot)
		- game->player.plane_y * sin(rot);
	game->player.plane_y = old_plane_x * sin(rot)
		+ game->player.plane_y * cos(rot);
}

static void	ft_apply_mouse_pitch(t_game *game, int delta_y)
{
	if (delta_y)
		game->player.pitch -= delta_y * MOUSE_PITCH_SENS;
	if (game->player.pitch > game->win_height / 2)
		game->player.pitch = game->win_height / 2;
	if (game->player.pitch < -game->win_height / 2)
		game->player.pitch = -game->win_height / 2;
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

	if (!game->mouse_init)
	{
		game->mouse_x = x;
		game->mouse_y = y;
		game->mouse_init = 1;
		return (0);
	}
	delta_x = ft_clamp_delta(x - game->mouse_x);
	delta_y = ft_clamp_delta(y - game->mouse_y);
	game->mouse_x = x;
	game->mouse_y = y;
	ft_apply_mouse_yaw(game, delta_x);
	ft_apply_mouse_pitch(game, delta_y);
	if (delta_x || delta_y)
	{
		mlx_mouse_move(game->mlx, game->win, game->win_width / 2,
			game->win_height / 2);
		game->mouse_x = game->win_width / 2;
		game->mouse_y = game->win_height / 2;
	}
	return (0);
}

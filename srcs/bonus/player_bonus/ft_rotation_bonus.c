/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotation_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 14:19:04 by aghergut          #+#    #+#             */
/*   Updated: 2026/05/06 14:39:04 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../../includes/bonus/cub3d_bonus.h"

static void	ft_rotate_player_fast(t_game *game, double cos_rot, double sin_rot)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player.dir_x;
	old_plane_x = game->player.plane_x;
	game->player.dir_x = old_dir_x * cos_rot - game->player.dir_y * sin_rot;
	game->player.dir_y = old_dir_x * sin_rot + game->player.dir_y * cos_rot;
	game->player.plane_x = old_plane_x * cos_rot - game->player.plane_y * sin_rot;
	game->player.plane_y = old_plane_x * sin_rot + game->player.plane_y * cos_rot;
}

void	ft_update_player(t_game *game)
{
	double	rot_step;
	double	cos_rot;
	double	sin_rot;

	if (game->key_w)
		ft_move_forward(game);
	if (game->key_s)
		ft_move_backward(game);
	if (game->key_a)
		ft_move_left(game);
	if (game->key_d)
		ft_move_right(game);
	rot_step = ROT_SPEED * game->delta_time;
	if (game->key_left)
	{
		cos_rot = cos(rot_step);
		sin_rot = sin(rot_step);
		ft_rotate_player_fast(game, cos_rot, sin_rot);
	}
	if (game->key_right)
	{
		cos_rot = cos(-rot_step);
		sin_rot = sin(-rot_step);
		ft_rotate_player_fast(game, cos_rot, sin_rot);
	}
}

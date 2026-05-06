/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-ru <vruiz-ru@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 18:11:23 by vruiz-ru          #+#    #+#             */
/*   Updated: 2026/05/06 18:20:25 by vruiz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/mandatory/cub3d.h"

static void	ft_rotate_player_fast(t_game *game, double cos_rot, double sin_rot)
{
	double	old_dir_x;
	double	old_pln_x;

	old_dir_x = game->kid.dir_x;
	old_pln_x = game->kid.pln_x;
	game->kid.dir_x = old_dir_x * cos_rot - game->kid.dir_y * sin_rot;
	game->kid.dir_y = old_dir_x * sin_rot + game->kid.dir_y * cos_rot;
	game->kid.pln_x = old_pln_x * cos_rot - game->kid.pln_y * sin_rot;
	game->kid.pln_y = old_pln_x * sin_rot + game->kid.pln_y * cos_rot;
}

void	ft_update_player(t_game *game)
{
	double	rot_step;
	double	cos_rot;
	double	sin_rot;

	ft_move_player(game);
	rot_step = ROT_SPEED * game->cron.delta_t;
	if (game->input.key_left)
	{
		cos_rot = cos(-rot_step);
		sin_rot = sin(-rot_step);
		ft_rotate_player_fast(game, cos_rot, sin_rot);
	}
	if (game->input.key_right)
	{
		cos_rot = cos(rot_step);
		sin_rot = sin(rot_step);
		ft_rotate_player_fast(game, cos_rot, sin_rot);
	}
}

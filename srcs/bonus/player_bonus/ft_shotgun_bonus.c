/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shotgun_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 14:19:08 by aghergut          #+#    #+#             */
/*   Updated: 2026/05/06 14:19:09 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/bonus/cub3d_bonus.h"

void	ft_init_shotgun(t_game *game)
{
	game->shotgun.state = SHOTGUN_IDLE;
	game->shotgun.ammo = SHOTGUN_MAX_AMMO;
	game->shotgun.animation_frame = 0;
	game->shotgun.animation_timer = 0;
}

static void	ft_update_shoot_anim(t_game *game)
{
	if (game->shotgun.animation_timer < 2)
		return ;
	game->shotgun.animation_timer = 0;
	game->shotgun.animation_frame++;
	if (game->shotgun.animation_frame < 15)
		return ;
	game->shotgun.animation_frame = 0;
	if (game->shotgun.ammo > 0)
		game->shotgun.state = SHOTGUN_IDLE;
	else
		game->shotgun.state = SHOTGUN_OUT_OF_AMMO;
}

void	ft_update_shotgun(t_game *game)
{
	game->shotgun.animation_timer++;
	if (game->shotgun.state == SHOTGUN_SHOOTING)
		ft_update_shoot_anim(game);
	else if (game->shotgun.state == SHOTGUN_RELOADING)
	{
		if (game->shotgun.animation_timer >= 4)
		{
			game->shotgun.animation_timer = 0;
			game->shotgun.animation_frame++;
			if (game->shotgun.animation_frame >= 7)
			{
				game->shotgun.animation_frame = 0;
				game->shotgun.ammo = SHOTGUN_MAX_AMMO;
				game->shotgun.state = SHOTGUN_IDLE;
			}
		}
	}
}

void	ft_shoot(t_game *game)
{
	if (game->shotgun.state != SHOTGUN_IDLE)
		return ;
	if (game->shotgun.ammo <= 0)
	{
		game->shotgun.state = SHOTGUN_OUT_OF_AMMO;
		return ;
	}
	game->shotgun.state = SHOTGUN_SHOOTING;
	game->shotgun.animation_frame = 0;
	game->shotgun.animation_timer = 0;
	game->shotgun.ammo--;
}

void	ft_reload_shotgun(t_game *game)
{
	if (game->shotgun.state == SHOTGUN_IDLE
		|| game->shotgun.state == SHOTGUN_OUT_OF_AMMO)
	{
		game->shotgun.state = SHOTGUN_RELOADING;
		game->shotgun.animation_frame = 0;
		game->shotgun.animation_timer = 0;
	}
}

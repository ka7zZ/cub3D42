/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hooks_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 14:15:47 by aghergut          #+#    #+#             */
/*   Updated: 2026/05/07 19:44:08 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/mandatory/cub3d.h"

static void	ft_set_move_key(int keycode, t_game *game)
{
	if (game->is_pressed)
		return ;
	if (keycode == XK_w || keycode == XK_W)
		game->input.key_w = 1;
	if (keycode == XK_s || keycode == XK_S)
		game->input.key_s = 1;
	if (keycode == XK_a || keycode == XK_A)
		game->input.key_a = 1;
	if (keycode == XK_d || keycode == XK_D)
		game->input.key_d = 1;
	if (keycode == XK_Left)
		game->input.key_left = 1;
	if (keycode == XK_Right)
		game->input.key_right = 1;
}

static void	ft_clear_move_key(int keycode, t_game *game)
{
	if (keycode == XK_w || keycode == XK_W)
		game->input.key_w = 0;
	if (keycode == XK_s || keycode == XK_S)
		game->input.key_s = 0;
	if (keycode == XK_a || keycode == XK_A)
		game->input.key_a = 0;
	if (keycode == XK_d || keycode == XK_D)
		game->input.key_d = 0;
	if (keycode == XK_Left)
		game->input.key_left = 0;
	if (keycode == XK_Right)
		game->input.key_right = 0;
}

int	ft_key_press(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		ft_close_game(game);
	ft_set_move_key(keycode, game);
	return (0);
}

int	ft_key_release(int keycode, t_game *game)
{
	ft_clear_move_key(keycode, game);
	return (0);
}

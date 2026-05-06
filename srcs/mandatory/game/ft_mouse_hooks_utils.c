/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_hooks_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-ru <vruiz-ru@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 14:15:47 by aghergut          #+#    #+#             */
/*   Updated: 2026/05/06 16:53:10 by vruiz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/mandatory/cub3d.h"

int	ft_mouse_pressed(int button, int x, int y, t_game *game)
{
	(void)button;
	(void)x;
	(void)y;
	game->is_pressed = true;
	game->input.key_w = 0;
	game->input.key_s = 0;
	game->input.key_a = 0;
	game->input.key_d = 0;
	game->input.key_left = 0;
	game->input.key_right = 0;
	return (1);
}

int	ft_mouse_released(int button, int x, int y, t_game *game)
{
	(void)button;
	(void)x;
	(void)y;
	game->is_pressed = false;
	return (1);
}

int	ft_focus_out(t_game *game)
{
	game->is_pressed = true;
	game->input.key_w = 0;
	game->input.key_s = 0;
	game->input.key_a = 0;
	game->input.key_d = 0;
	game->input.key_left = 0;
	game->input.key_right = 0;
	return (0);
}

int	ft_focus_in(t_game *game)
{
	game->is_pressed = false;
	return (0);
}

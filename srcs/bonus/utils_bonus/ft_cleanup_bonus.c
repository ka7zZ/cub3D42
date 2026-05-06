/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanup_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 14:20:28 by aghergut          #+#    #+#             */
/*   Updated: 2026/05/06 14:20:30 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/bonus/cub3d_bonus.h"

void	ft_free_game(t_game *game)
{
	if (!game)
		return ;
	if (game->frame.img && game->mlx)
		mlx_destroy_image(game->mlx, game->frame.img);
	if (game->mlx)
		ft_free_textures(game);
	if (game->z_buffer)
	{
		free(game->z_buffer);
		game->z_buffer = NULL;
	}
	if (game->win && game->mlx)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
	ft_mapfree(&game->map);
	ft_mapfree(&game->original_map);
	free(game->tex_no_path);
	free(game->tex_so_path);
	free(game->tex_we_path);
	free(game->tex_ea_path);
}

void	ft_exit_error(t_game *game, char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	if (game)
		ft_free_game(game);
	exit(1);
}

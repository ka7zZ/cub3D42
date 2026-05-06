/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 15:41:07 by vruiz-ru          #+#    #+#             */
/*   Updated: 2026/05/06 14:26:42 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/mandatory/cub3d.h"

void	ft_free_game(t_game *game)
{
	if (!game)
		return ;
	if (game->graph.frame.img && game->graph.mlx)
		mlx_destroy_image(game->graph.mlx, game->graph.frame.img);
	if (game->graph.mlx)
		ft_free_textures(game);
	if (game->graph.win && game->graph.mlx)
		mlx_destroy_window(game->graph.mlx, game->graph.win);
	if (game->graph.mlx)
	{
		mlx_destroy_display(game->graph.mlx);
		free(game->graph.mlx);
		game->graph.mlx = NULL;
	}
	ft_mapfree(&game->map.map);
	free(game->assets.tex_no_path);
	free(game->assets.tex_so_path);
	free(game->assets.tex_we_path);
	free(game->assets.tex_ea_path);
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

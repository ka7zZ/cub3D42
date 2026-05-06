/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-ru <vruiz-ru@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 14:20:38 by aghergut          #+#    #+#             */
/*   Updated: 2026/05/06 20:35:54 by vruiz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/bonus/cub3d_bonus.h"

void	ft_init_mlx(t_game *game)
{
	int	screen_width;
	int	screen_height;

	game->graph.mlx = mlx_init();
	if (!game->graph.mlx)
		ft_exit_error(game, "MLX initialization failed");
	mlx_get_screen_size(game->graph.mlx, &screen_width, &screen_height);
	game->graph.win_width = screen_width;
	game->graph.win_height = screen_height;
	game->graph.win = mlx_new_window(game->graph.mlx, game->graph.win_width,
			game->graph.win_height, "cub3D");
	if (!game->graph.win)
		ft_exit_error(game, "Window creation failed");
	game->graph.frame.img = mlx_new_image(game->graph.mlx,
			game->graph.win_width, game->graph.win_height);
	if (!game->graph.frame.img)
		ft_exit_error(game, "Image creation failed");
	game->graph.frame.addr = mlx_get_data_addr(game->graph.frame.img,
			&game->graph.frame.bpp,
			&game->graph.frame.line_len,
			&game->graph.frame.endian);
	game->z_buffer = (double *)malloc(sizeof(double) * game->graph.win_width);
	if (!game->z_buffer)
		ft_exit_error(game, "Z-buffer allocation failed");
}

int	ft_init_game(t_game *game, char *map_file)
{
	ft_memset(game, 0, sizeof(t_game));
	if (!ft_init_stage_map_window(game, map_file))
	{
		ft_free_game(game);
		return (0);
	}
	if (!ft_init_stage_assets_world(game))
	{
		ft_free_game(game);
		return (0);
	}
	ft_init_stage_runtime(game);
	ft_print_controls();
	return (1);
}

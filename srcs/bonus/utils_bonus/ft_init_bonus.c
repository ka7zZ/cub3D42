/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 14:20:38 by aghergut          #+#    #+#             */
/*   Updated: 2026/05/06 14:20:39 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/bonus/cub3d_bonus.h"

void	ft_init_mlx(t_game *game)
{
	int	screen_width;
	int	screen_height;

	game->mlx = mlx_init();
	if (!game->mlx)
		ft_exit_error(game, "MLX initialization failed");
	mlx_get_screen_size(game->mlx, &screen_width, &screen_height);
	game->win_width = screen_width;
	game->win_height = screen_height;
	game->win = mlx_new_window(game->mlx, game->win_width,
			game->win_height, "so_long 3D");
	if (!game->win)
		ft_exit_error(game, "Window creation failed");
	game->frame.img = mlx_new_image(game->mlx,
			game->win_width, game->win_height);
	if (!game->frame.img)
		ft_exit_error(game, "Image creation failed");
	game->frame.addr = mlx_get_data_addr(game->frame.img,
			&game->frame.bpp, &game->frame.line_len, &game->frame.endian);
	game->z_buffer = (double *)malloc(sizeof(double) * game->win_width);
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

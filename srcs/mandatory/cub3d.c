/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-ru <vruiz-ru@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 00:00:00 by vruiz-ru          #+#    #+#             */
/*   Updated: 2026/05/06 17:55:21 by vruiz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mandatory/cub3d.h"

static int	ft_file_exists(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}

static char	*ft_resolve_map_path(char *input)
{
	int	len;

	if (!input)
		return (NULL);
	len = (int)ft_strlen(input);
	if (len < 4 || ft_strncmp(input + len - 4, ".cub", 4) != 0)
		return (NULL);
	if (ft_file_exists(input))
		return (ft_strdup(input));
	return (NULL);
}

static void	ft_set_hooks(t_game *game)
{
	mlx_loop_hook(game->graph.mlx, ft_game_loop, game);
	mlx_hook(game->graph.win, KeyPress, KeyPressMask, ft_key_press, game);
	mlx_hook(game->graph.win, KeyRelease, KeyReleaseMask, ft_key_release, game);
	mlx_hook(game->graph.win, DestroyNotify, NoEventMask, ft_close_game, game);
	mlx_hook(game->graph.win, ButtonPress, ButtonPressMask,
		ft_mouse_pressed, game);
	mlx_hook(game->graph.win, ButtonRelease, ButtonReleaseMask,
		ft_mouse_released, game);
	mlx_hook(game->graph.win, FocusOut, FocusChangeMask, ft_focus_out, game);
	mlx_hook(game->graph.win, FocusIn, FocusChangeMask, ft_focus_in, game);
}

int	main(int argc, char **argv)
{
	t_game	game;
	char	*map_path;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nUsage: ./cub3d <scene.cub>\n", 2);
		return (1);
	}
	map_path = ft_resolve_map_path(argv[1]);
	if (!map_path)
	{
		ft_putstr_fd("Error\nMap file not found\n", 2);
		return (1);
	}
	if (!ft_init_game(&game, map_path))
	{
		free(map_path);
		ft_putstr_fd("Error\nGame initialization failed\n", 2);
		return (1);
	}
	free(map_path);
	ft_set_hooks(&game);
	mlx_loop(game.graph.mlx);
	return (0);
}

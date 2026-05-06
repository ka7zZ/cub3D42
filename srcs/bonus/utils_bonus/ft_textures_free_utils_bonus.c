/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures_free_utils_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-ru <vruiz-ru@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 14:20:53 by aghergut          #+#    #+#             */
/*   Updated: 2026/05/06 20:22:43 by vruiz-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/bonus/cub3d_bonus.h"

void	ft_free_dual_wall_textures(t_game *g)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (g->assets.tex_wall_dark[i].img)
			mlx_destroy_image(g->graph.mlx, g->assets.tex_wall_dark[i].img);
		i++;
	}
}

void	ft_free_array_tex(t_game *g, t_texture *arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (arr[i].img)
			mlx_destroy_image(g->graph.mlx, arr[i].img);
		i++;
	}
}

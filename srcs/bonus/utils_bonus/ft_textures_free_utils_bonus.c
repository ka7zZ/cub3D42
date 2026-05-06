/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures_free_utils_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 14:20:53 by aghergut          #+#    #+#             */
/*   Updated: 2026/05/06 14:20:55 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/bonus/cub3d_bonus.h"

void	ft_free_dual_wall_textures(t_game *g)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (g->tex_wall_dark[i].img)
			mlx_destroy_image(g->mlx, g->tex_wall_dark[i].img);
		i++;
	}
}

void	ft_free_array_textures(t_game *g, t_texture *arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (arr[i].img)
			mlx_destroy_image(g->mlx, arr[i].img);
		i++;
	}
}

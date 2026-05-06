/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures_free_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 14:17:42 by aghergut          #+#    #+#             */
/*   Updated: 2026/05/06 14:26:42 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/mandatory/cub3d.h"

void	ft_free_dual_wall_textures(t_game *g)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (g->assets.tex_wall[i].img)
			mlx_destroy_image(g->graph.mlx, g->assets.tex_wall[i].img);
		i++;
	}
}

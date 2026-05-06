/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapitem_index.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.org    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 20:12:06 by aghergut          #+#    #+#             */
/*   Updated: 2025/12/10 18:17:23 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maps.h"

int	ft_mapitem_index(char **map, char *str)
{
	size_t	mv_len;
	size_t	sv_len;
	size_t	idx;

	if (!map || !*map || !str || !*str)
		return (-1);
	sv_len = right_length(str);
	idx = 0;
	while (map[idx])
	{
		mv_len = right_length(map[idx]);
		if (mv_len == sv_len && !ft_strncmp(map[idx], str, mv_len))
			return (idx);
		idx++;
	}
	return (-1);
}

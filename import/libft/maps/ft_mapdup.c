/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.org    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 18:41:48 by aghergut          #+#    #+#             */
/*   Updated: 2025/12/10 18:17:23 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maps.h"

char	**ft_mapdup(char **map)
{
	char	**dup;
	size_t	length;
	int		i;

	length = ft_mapsize(map);
	dup = (char **)malloc((length + 1) * sizeof(char *));
	if (!dup)
		return (NULL);
	if (!map || !*map)
	{
		dup[0] = NULL;
		return (dup);
	}
	i = 0;
	while (map[i])
	{
		dup[i] = ft_strdup(map[i]);
		if (!dup[i])
			return (free_partial(dup, i), free(dup), NULL);
		i++;
	}
	dup[i] = NULL;
	return (dup);
}

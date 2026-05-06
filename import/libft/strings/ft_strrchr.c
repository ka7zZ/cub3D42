/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.org    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:50:14 by aghergut          #+#    #+#             */
/*   Updated: 2025/12/10 18:17:23 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"

char	*ft_strrchr(const char *str, int ch)
{
	char	*res;
	int		i;

	if (!str)
		return (NULL);
	res = (char *)str;
	i = ft_strlen(res);
	while (i >= 0)
	{
		if (res[i] == (char)ch)
			return (res + i);
		i--;
	}
	return (0);
}

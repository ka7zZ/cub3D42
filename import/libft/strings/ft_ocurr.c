/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ocurr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 11:52:52 by aghergut          #+#    #+#             */
/*   Updated: 2026/05/07 19:54:46 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"

int	ft_ocurr(char *str, char ch)
{
	int	ocurr;
	int	idx;

	ocurr = 0;
	idx = 0;
	while (str[idx])
	{
		if (str[idx] == ch)
			ocurr++;
		idx++;
	}
	return (ocurr);
}

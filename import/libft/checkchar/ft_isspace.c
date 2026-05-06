/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.org    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 06:33:32 by aghergut          #+#    #+#             */
/*   Updated: 2025/12/10 18:48:48 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../strings/strings.h"

int	ft_isspace(int ch)
{
	if (ft_strchr(" \t\n\v\f\r", ch))
		return (1);
	return (0);
}

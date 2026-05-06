/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_3d_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 14:21:04 by aghergut          #+#    #+#             */
/*   Updated: 2026/05/06 14:21:05 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/bonus/cub3d_bonus.h"

void	ft_print_controls(void)
{
	ft_printf("\n=== SO_LONG 3D - CONTROLS ===\n");
	ft_printf("W/S         - Move Forward/Backward\n");
	ft_printf("A/D         - Strafe Left/Right\n");
	ft_printf("LEFT/RIGHT  - Rotate\n");
	ft_printf("MOUSE       - Rotate\n");
	ft_printf("LEFT-CLICK  - Shoot\n");
	ft_printf("E           - Interact\n");
	ft_printf("R           - Reload\n");
	ft_printf("ESC         - Exit Game\n");
	ft_printf("============================\n\n");
}

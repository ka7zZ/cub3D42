/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 14:18:14 by aghergut          #+#    #+#             */
/*   Updated: 2026/05/06 14:18:16 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_BONUS_H
# define MACROS_BONUS_H

/* Window and texture sizes */
# define WIN_WIDTH			1280
# define WIN_HEIGHT			720
# define TEX_WIDTH			64
# define TEX_HEIGHT			64

/* Movement and camera */
# define MOVE_SPEED			3.8
# define ROT_SPEED			1.8
# define PLAYER_RADIUS		0.18
# define DOOR_ANIM_SMOOTH	0.20
# define MIN_DELTA_TIME		0.008
# define MAX_DELTA_TIME		0.080
# define MOUSE_YAW_SENS		0.00035
# define MOUSE_PITCH_SENS	0.16

/* Raycast quality switch: 1 = max quality, 0 = performance */
# define RAYCAST_MAX_QUALITY	0
# if RAYCAST_MAX_QUALITY
#  define RAYCAST_COLUMN_STEP	1
# else
#  define RAYCAST_COLUMN_STEP	2
# endif

/* Limits */
# define MAX_DOORS			64

/* Shotgun */
# define SHOTGUN_MAX_AMMO	8

/* Interaction */
# define INTERACT_RANGE		2.0

/* Door Auto-Close */
# define DOOR_AUTO_CLOSE_FRAMES	60

#endif

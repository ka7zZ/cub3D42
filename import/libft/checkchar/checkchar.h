/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkchar.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:38:56 by aghergut          #+#    #+#             */
/*   Updated: 2025/12/07 06:35:39 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKCHAR_H
# define CHECKCHAR_H

# include <unistd.h>

int	ft_isalnum(int c);
int	ft_isalpha(int c);
int	ft_isascii(int c);
int	ft_isdigit(int c);
int	ft_isprint(int c);
int	ft_isspace(int ch);
#endif
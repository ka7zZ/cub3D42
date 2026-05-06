/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floodfill_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 14:20:33 by aghergut          #+#    #+#             */
/*   Updated: 2026/05/06 14:20:34 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/bonus/cub3d_bonus.h"

static void	ft_try_push(t_fill_ctx *ctx, t_mapxy pos)
{
	if (pos.x < 0 || pos.y < 0 || pos.x >= ctx->dim->y || pos.y >= ctx->dim->x)
		return ;
	if (ctx->map[pos.x][pos.y] == '1' || ctx->map[pos.x][pos.y] == 'V')
		return ;
	ctx->map[pos.x][pos.y] = 'V';
	ctx->sx[++ctx->top] = pos.x;
	ctx->sy[ctx->top] = pos.y;
}

static void	ft_fill_loop(t_fill_ctx *ctx)
{
	t_mapxy	cur;

	ctx->top = 0;
	while (ctx->top >= 0)
	{
		cur = (t_mapxy){ctx->sx[ctx->top], ctx->sy[ctx->top--]};
		ft_try_push(ctx, (t_mapxy){cur.x - 1, cur.y});
		ft_try_push(ctx, (t_mapxy){cur.x + 1, cur.y});
		ft_try_push(ctx, (t_mapxy){cur.x, cur.y - 1});
		ft_try_push(ctx, (t_mapxy){cur.x, cur.y + 1});
	}
}

void	ft_floodfill(char **map, t_mapxy *point, int x, int y)
{
	t_fill_ctx	ctx;
	int			max;

	if (x < 0 || y < 0 || x >= point->y || y >= point->x)
		return ;
	if (map[x][y] == '1' || map[x][y] == 'V')
		return ;
	max = point->x * point->y;
	if (max <= 0)
		return ;
	ctx.sx = (int *)malloc(sizeof(int) * max);
	ctx.sy = (int *)malloc(sizeof(int) * max);
	if (!ctx.sx || !ctx.sy)
		return ((void)free(ctx.sx), (void)free(ctx.sy));
	ctx.map = map;
	ctx.dim = point;
	map[x][y] = 'V';
	ctx.sx[0] = x;
	ctx.sy[0] = y;
	ft_fill_loop(&ctx);
	free(ctx.sx);
	free(ctx.sy);
}

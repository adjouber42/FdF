/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_iso.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 13:34:31 by adjouber          #+#    #+#             */
/*   Updated: 2018/12/20 17:09:52 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_seg(t_fdf *fdf, int *xy, int x, int y)
{
	int	tabx[2];
	int	taby[2];
	int	e[2];
	int x0;
	int	y0;

	x0 = xy[0];
	y0 = xy[1];
	tabx[0] = abs(x - x0);
	tabx[1] = x0 < x ? 1 : -1;
	taby[0] = abs(y - y0);
	taby[1] = y0 < y ? 1 : -1;
	e[0] = (tabx[0] > taby[0] ? tabx[0] : -tabx[0]) / 2;
	while (x0 != x || y0 != y)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, x0, y0, 0x00FFFFFF);
		e[1] = e[0];
		e[1] > -tabx[0] ? e[0] -= taby[0] : 1 == 1;
		e[1] > -tabx[0] ? x0 += tabx[1] : 1 == 1;
		e[1] < taby[0] ? e[0] += tabx[0] : 1 == 1;
		e[1] < taby[0] ? y0 += taby[1] : 1 == 1;
	}
}

static void	draw_lines(t_fdf *fdf, int x, int y)
{
	int	xy[2];

	xy[0] = fdf->dx + (x - y);
	xy[1] = fdf->dy + fdf->map[y / fdf->sy][x / fdf->sx] * fdf->z + x + y;
	if (x / fdf->sx < fdf->points - 1 && y / fdf->sy < fdf->lines)
		draw_seg(fdf, xy, fdf->dx + ((x + fdf->sx) - y), fdf->dy
				+ fdf->map[y / fdf->sy][x / fdf->sx + 1]
				* fdf->z + (x + fdf->sx) + y);
	if (y / fdf->sy < fdf->lines - 1 && x / fdf->sx < fdf->points)
		draw_seg(fdf, xy, fdf->dx + (x - (fdf->sy + y)), fdf->dy
				+ fdf->map[y / fdf->sy + 1][x / fdf->sx]
				* fdf->z + x + (fdf->sy + y));
}

static void	init_draw(t_fdf *fdf)
{
	if (fdf->check == 0)
	{
		fdf->z = -5;
		fdf->dx = LON * 0.4;
		fdf->dy = 100;
		fdf->sx = (LON * 0.3) / (fdf->points - 1);
		fdf->sy = (HAU * 0.2) / (fdf->lines - 1);
		fdf->projection = 1;
	}
	fdf->check++;
}

void		draw_iso(t_fdf *fdf)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	init_draw(fdf);
	while (x / fdf->sx < fdf->points || y / fdf->sy < fdf->lines - 1)
	{
		if (x / fdf->sx == fdf->points)
		{
			x = 0;
			y += fdf->sy;
		}
		draw_lines(fdf, x, y);
		x += fdf->sx;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:24:37 by adjouber          #+#    #+#             */
/*   Updated: 2018/12/26 14:05:17 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		bleu(t_fdf *fdf)
{
	fdf->color_set = 3;
	fdf->color = 0xFF00FF;
	fdf->color_mult = 256 * 256;
	fdf->fin = 256;
}

void		vert(t_fdf *fdf)
{
	fdf->color_set = 2;
	fdf->color = 0x00FFFF;
	fdf->color_mult = 1;
	fdf->fin = 256 * 256;
}

void		rouge(t_fdf *fdf)
{
	fdf->color_set = 1;
	fdf->color = 0xFFFF00;
	fdf->color_mult = 256;
	fdf->fin = 1;
}

static int	ft_color(int res, t_fdf *fdf)
{
	res = -res * 2;
	if (res >= 0)
		return (fdf->color - res * fdf->color_mult);
	else
		return (fdf->color - res * fdf->fin);
}

int			color(t_fdf *fdf, int i, int k, int j)
{
	int	res;
	int	dx;
	int	dy;

	dx = fdf->coorf[k].x - fdf->coorf[i].x;
	dy = fdf->coorf[k].y - fdf->coorf[i].y;
	dx = (dx >= 0) ? dx : -dx;
	dy = (dy >= 0) ? dy : -dy;
	if (dx >= dy)
		res = ft_color(fdf->coord[i].z * 10 + j * 10 *
				(fdf->coord[k].z - fdf->coord[i].z) / dx, fdf);
	else
		res = ft_color(fdf->coord[i].z * 10 + j * 10 *
				(fdf->coord[k].z - fdf->coord[i].z) / dy, fdf);
	return (res);
}

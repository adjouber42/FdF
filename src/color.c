/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:24:37 by adjouber          #+#    #+#             */
/*   Updated: 2018/12/21 18:21:06 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_color(int res)
{
	res = -res * 2;
	if (res < -3 * 255)
		return (0x0000FF);
	else if (res < -2 * 255 && res >= -3 * 255)
		return (0x00FFFF - (res * -1 - 2 * 255) * 256);
	else if (res < -1 * 255 && res >= -2 * 255)
		return (0x00FF00 + (res * -1 - 1 * 255));
	else if (res < 0 * 255 && res >= -1 * 255)
		return (0xFFFF00 + res * 256 * 256);
	else if (res < 1 * 255 && res >= 0 * 255)
		return (0xFFFF00 - 256 * res);
	else if (res < 2 * 255 && res >= 1 * 255)
		return (0xFF0000 + res - 256);
	else if (res < 3 * 255 && res >= 2 * 255)
		return (0xFF00FF + (res - 2 * 256) * 256);
	else
		return (0xFFFFFF);
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
	{
		res = ft_color(fdf->coord[i].z * 10 + j * 10 *
				(fdf->coord[k].z - fdf->coord[i].z) / dx);
	}
	else
	{
		res = ft_color(fdf->coord[i].z * 10 + j * 10 *
				(fdf->coord[k].z - fdf->coord[i].z) / dy);
	}
	return (res);
}

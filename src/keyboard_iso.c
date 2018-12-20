/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_iso.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 13:51:17 by adjouber          #+#    #+#             */
/*   Updated: 2018/12/20 17:14:56 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	zoom_iso(int key, t_fdf *fdf)
{
	if (key == 69)
	{
		if (fdf->zoom_limit != 6)
		{
			mlx_clear_window(fdf->mlx, fdf->win);
			fdf->sx *= 1.5;
			fdf->sy *= 1.5;
			fdf->z *= 1.5;
			fdf->zoom_limit++;
			draw_iso(fdf);
		}
	}
	if (key == 78)
	{
		if (fdf->zoom_limit != 0)
		{
			mlx_clear_window(fdf->mlx, fdf->win);
			fdf->sx /= 1.5;
			fdf->sy /= 1.5;
			fdf->z /= 1.5;
			fdf->zoom_limit--;
			draw_iso(fdf);
		}
	}
}

static void	decal_iso(int key, t_fdf *fdf)
{
	if ((key >= 123 && key <= 126) || key == 49)
	{
		mlx_clear_window(fdf->mlx, fdf->win);
		if (key == 123)
			fdf->dx -= 10;
		if (key == 124)
			fdf->dx += 10;
		if (key == 125)
			fdf->dy += 10;
		if (key == 126)
			fdf->dy -= 10;
		if (key == 49)
			fdf->check = 0;
		draw_iso(fdf);
	}
}

void		keyboard_iso(int key, t_fdf *fdf)
{
	if (key == 69 || key == 78)
		zoom_iso(key, fdf);
	if ((key >= 123 && key <= 126) || key == 49)
		decal_iso(key, fdf);
}

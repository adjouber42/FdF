/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_par.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 14:04:20 by adjouber          #+#    #+#             */
/*   Updated: 2018/12/20 17:11:41 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	zoom_par(int key, t_fdf *fdf)
{
	int	i;

	i = 0;
	if (key == 69 && fdf->zoom_limit <= 6)
	{
		while (i < fdf->lines * fdf->points)
		{
			fdf->coorf[i].x *= 1.5;
			fdf->coorf[i].y *= 1.5;
			i++;
		}
		fdf->zoom_limit++;
	}
	if (key == 78 && fdf->zoom_limit >= 0)
	{
		while (i < fdf->lines * fdf->points)
		{
			fdf->coorf[i].x /= 1.5;
			fdf->coorf[i].y /= 1.5;
			i++;
		}
		fdf->zoom_limit--;
	}
	mlx_clear_window(fdf->mlx, fdf->win);
	display(fdf);
}

static void	decal_par2(int key, t_fdf *fdf, int i)
{
	if (key == 125)
		while (i < fdf->lines * fdf->points)
		{
			fdf->coorf[i].y += 10;
			i++;
		}
	if (key == 126)
		while (i < fdf->lines * fdf->points)
		{
			fdf->coorf[i].y -= 10;
			i++;
		}
}

static void	decal_par(int key, t_fdf *fdf, int i)
{
	if (key == 123)
		while (i < fdf->lines * fdf->points)
		{
			fdf->coorf[i].x -= 10;
			i++;
		}
	if (key == 124)
		while (i < fdf->lines * fdf->points)
		{
			fdf->coorf[i].x += 10;
			i++;
		}
	decal_par2(key, fdf, i);
	mlx_clear_window(fdf->mlx, fdf->win);
	display(fdf);
}

void		keyboard_par(int key, t_fdf *fdf)
{
	if (key == 69 || key == 78)
		zoom_par(key, fdf);
	if (key >= 123 && key <= 126)
		decal_par(key, fdf, 0);
	if (key == 49)
	{
		mlx_clear_window(fdf->mlx, fdf->win);
		free(fdf->coorf);
		draw_par(fdf);
	}
}

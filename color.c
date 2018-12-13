/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:24:37 by adjouber          #+#    #+#             */
/*   Updated: 2018/12/13 17:13:27 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	red(t_fdf *fdf)
{
	if (fdf->color.color_set != 0)
	{
		fdf->color.color_set = 0;
		fdf->color.color1 = 0x00FFFFFF;
		fdf->color.color2 = 0x00FFFFCC;
		fdf->color.color3 = 0x00FFFF88;
		fdf->color.color4 = 0x00FFFF44;
		fdf->color.color5 = 0x00FFFF00;
		fdf->color.color6 = 0x00FFCC00;
		fdf->color.color7 = 0x00FF8800;
		fdf->color.color8 = 0x00FF4400;
		fdf->color.color9 = 0x00FF0000;
	}
}

void	blue(t_fdf *fdf)
{
	if (fdf->color.color_set != 1)
	{
		fdf->color.color_set = 1;
		fdf->color.color1 = 0x00FFFFFF;
		fdf->color.color2 = 0x00FFCCFF;
		fdf->color.color3 = 0x00FF88FF;
		fdf->color.color4 = 0x00FF44FF;
		fdf->color.color5 = 0x00FF00FF;
		fdf->color.color6 = 0x00CC00FF;
		fdf->color.color7 = 0x008800FF;
		fdf->color.color8 = 0x004400FF;
		fdf->color.color9 = 0x000000FF;
	}
}

void	green(t_fdf *fdf)
{
	if (fdf->color.color_set != 2)
	{
		fdf->color.color_set = 2;
		fdf->color.color1 = 0x00FFFFFF;
		fdf->color.color2 = 0x00CCFFFF;
		fdf->color.color3 = 0x0088FFFF;
		fdf->color.color4 = 0x0044FFFF;
		fdf->color.color5 = 0x0000FFFF;
		fdf->color.color6 = 0x0000FFCC;
		fdf->color.color7 = 0x0000FF88;
		fdf->color.color8 = 0x0000FF44;
		fdf->color.color9 = 0x0000FF00;
	}
}

void	color(t_fdf *fdf, int x, int y)
{
	if (fdf->map[y / fdf->sy][x / fdf->sx] == fdf->min)
		fdf->color_put = fdf->color.color1;
	if (fdf->map[y / fdf->sy][x / fdf->sx] == fdf->max)
		fdf->color_put = fdf->color.color9;
	if (fdf->map[y / fdf->sy][x / fdf->sx] == fdf->max)
		fdf->color_put = fdf->color.color9;
}

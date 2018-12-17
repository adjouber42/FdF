/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:24:37 by adjouber          #+#    #+#             */
/*   Updated: 2018/12/17 15:32:47 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	red(t_fdf *fdf)
{
	if (fdf->color.color_set != 0)
	{
		fdf->color.color_set = 0;
		fdf->color.color1 = 0x00FFFFFF;
		fdf->color.color4 = 0x00FFFF44;
		fdf->color.color6 = 0x00FFCC00;
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
		fdf->color.color4 = 0x00FF44FF;
		fdf->color.color6 = 0x00CC00FF;
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
		fdf->color.color4 = 0x00AAFFFF;
		fdf->color.color6 = 0x0000FFFF;
		fdf->color.color8 = 0x0000FFAA;
		fdf->color.color9 = 0x0000FF00;
	}
}

void	color(t_fdf *fdf, int x, int y)
{
	int	z;

	z = fdf->map[y / fdf->sy][x / fdf->sx];
	if (z == fdf->min)
		fdf->color_put = fdf->color.color1;
	else if (z > fdf->min && z < fdf->max/2)
		fdf->color_put = fdf->color.color4;
	else if (z == fdf->max / 2)
		fdf->color_put = fdf->color.color6;
	else if (z > fdf->max / 2 && z < fdf->max)
		fdf->color_put = fdf->color.color8;
	else if (z == fdf->max)
		fdf->color_put = fdf->color.color9;
}

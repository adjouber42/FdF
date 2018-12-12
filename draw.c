/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 13:55:49 by adjouber          #+#    #+#             */
/*   Updated: 2018/12/12 14:53:01 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_draw(t_fdf *fdf)
{
	if (fdf->check == 0)
	{
		fdf->z = -5;
		fdf->dx = LON * 0.4;
		fdf->dy = 20;
		fdf->sx = (LON * 0.5) / (fdf->points - 1);
		fdf->sy = (HAU * 0.3) / (fdf->lines - 1);
		fdf->color = 0x00FFFFFF;
	}
	fdf->check++;
}

void	draw(t_fdf *fdf)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	init_draw(fdf);
	
}

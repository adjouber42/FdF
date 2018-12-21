/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 18:19:42 by adjouber          #+#    #+#             */
/*   Updated: 2018/12/21 18:35:40 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static void	zoom_par(int key, t_fdf *fdf)
{
	int	i;

	i = 0;
	ft_bzero(fdf->data, LON * HAU * 4);
	if (key == 24)
	{
		while (i < fdf->lines * fdf->points)
		{
			fdf->coorf[i].x *= 1.5;
			fdf->coorf[i].y *= 1.5;
			i++;
		}
	}
	if (key == 27)
	{
		while (i < fdf->lines * fdf->points)
		{
			fdf->coorf[i].x /= 1.5;
			fdf->coorf[i].y /= 1.5;
			i++;
		}
	}
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
	ft_bzero(fdf->data, LON * HAU * 4);
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
	display(fdf);
}

static void	profondeur(int key, t_fdf *fdf)
{
	ft_bzero(fdf->data, LON *HAU * 4);
	if (key == 47)
		fdf->coef--;
	if (key == 43)
		fdf->coef++;
	free(fdf->coorf);
	projection(fdf);
}

void		keyboard_max(int key, t_fdf *fdf)
{
	if (key == 24 || key == 27)
		zoom_par(key, fdf);
	if (key >= 123 && key <= 126)
		decal_par(key, fdf, 0);
	if (key == 47 || key == 43)
		profondeur(key, fdf);
	if (key == 49)
	{
		ft_bzero(fdf->data, LON * HAU * 4);
		free(fdf->coorf);
		draw(fdf);
	}
	printf("%d\n", key);
}

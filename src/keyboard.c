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

static void	zoom_profondeur(int key, t_fdf *fdf)
{
	int	i;

	i = 0;
	ft_bzero(fdf->data, LON * HAU * 4);
	if (key == 24)
		fdf->zoom *= 2;
	if (key == 27)
		if (fdf->zoom / 2 != 0)
			fdf->zoom /= 2;
	if (key == 47)
		fdf->coef--;
	if (key == 43)
		fdf->coef++;
	free(fdf->coorf);
	projection(fdf);
	commande(fdf);
}

static void	decal2(int key, t_fdf *fdf, int i)
{
	if (key == 125)
		while (i < fdf->lines * fdf->points)
		{
			fdf->coord[i].y += 1;
			if (fdf->projection == 1)
				fdf->coord[i].x += 1;
			i++;
		}
	if (key == 126)
		while (i < fdf->lines * fdf->points)
		{
			fdf->coord[i].y -= 1;
			if (fdf->projection == 1)
				fdf->coord[i].x -= 1;
			i++;
		}
}

static void	decal(int key, t_fdf *fdf, int i)
{
	ft_bzero(fdf->data, LON * HAU * 4);
	if (key == 123)
		while (i < fdf->lines * fdf->points)
		{
			fdf->coord[i].x -= 1;
			if (fdf->projection == 1)
				fdf->coord[i].y += 1;
			i++;
		}
	if (key == 124)
		while (i < fdf->lines * fdf->points)
		{
			fdf->coord[i].x += 1;
			if (fdf->projection == 1)
				fdf->coord[i].y -= 1;
			i++;
		}
	decal2(key, fdf, i);
	projection(fdf);
	commande(fdf);
}

static void	color_choose(int key, t_fdf *fdf)
{
	if (key == 15 && fdf->color_set != 1)
	{
		ft_bzero(fdf->data, LON * HAU * 4);
		rouge(fdf);
		display(fdf);
	}
	if (key == 9 && fdf->color_set != 2)
	{
		ft_bzero(fdf->data, LON * HAU * 4);
		vert(fdf);
		display(fdf);
	}
	if (key == 11 && fdf->color_set != 3)
	{
		ft_bzero(fdf->data, LON * HAU * 4);
		bleu(fdf);
		display(fdf);
	}
	commande(fdf);
}

void		keyboard_max(int key, t_fdf *fdf)
{
	if (key == 24 || key == 27 || key == 47 || key == 43)
		zoom_profondeur(key, fdf);
	if (key >= 123 && key <= 126)
		decal(key, fdf, 0);
	if (key == 15 || key == 9 || key == 11)
		color_choose(key, fdf);
	if (key == 49)
	{
		ft_bzero(fdf->data, LON * HAU * 4);
		free(fdf->coorf);
		fdf->coef = 1;
		fdf->projection = 2;
		fdf->zoom = LON / (fdf->points + fdf->lines);
		rouge(fdf);
		draw(fdf);
		commande(fdf);
	}
}

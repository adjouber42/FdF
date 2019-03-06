/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 18:15:51 by adjouber          #+#    #+#             */
/*   Updated: 2019/03/06 14:43:52 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	projection_iso(t_fdf *fdf)
{
	int i;

	i = 0;
	if (!(fdf->coorf = ft_memalloc(sizeof(t_coorf) * fdf->lines * fdf->points)))
		return ;
	while (i < fdf->lines * fdf->points)
	{
		fdf->coorf[i].x = (float)fdf->coord[i].x * 0.5 * fdf->zoom -
				(float)fdf->coord[i].y * 0.5 * fdf->zoom;
		fdf->coorf[i].y = (float)fdf->coord[i].z * fdf->zoom * 0.1 * fdf->coef +
			0.5 / 2 * fdf->zoom * fdf->coord[i].x + 0.5 / 2 * fdf->zoom *
			(float)fdf->coord[i].y;
		i++;
	}
	display(fdf);
}

static void	projection_par(t_fdf *fdf)
{
	int	i;

	i = 0;
	if (!(fdf->coorf = ft_memalloc(sizeof(t_coorf) * fdf->lines * fdf->points)))
		return ;
	while (i < fdf->lines * fdf->points)
	{
		fdf->coorf[i].x = (float)fdf->coord[i].x * fdf->zoom * 0.7
			+ (float)fdf->coord[i].z * fdf->coef * 0.05 * fdf->zoom;
		fdf->coorf[i].y = (float)fdf->coord[i].y * fdf->zoom * 0.7
			+ (float)fdf->coord[i].z * fdf->coef * 0.05 * fdf->zoom / 2;
		i++;
	}
	display(fdf);
}

void		projection(t_fdf *fdf)
{
	if (fdf->projection == 1)
	{
		fdf->dx = 800;
		projection_iso(fdf);
	}
	if (fdf->projection == 2)
	{
		fdf->dx = 550;
		projection_par(fdf);
	}
}

void		draw(t_fdf *fdf)
{
	int	i;
	int	j;
	int k;

	if (!(fdf->coord = ft_memalloc(sizeof(t_coord) * fdf->lines * fdf->points)))
		return ;
	i = 0;
	k = 0;
	while (i < fdf->lines)
	{
		j = 0;
		while (j < fdf->points)
		{
			fdf->coord[k].x = j + 1;
			fdf->coord[k].y = i + 1;
			fdf->coord[k].z = -fdf->map[i][j];
			j++;
			if (j < fdf->points)
				k++;
		}
		i++;
		if (i < fdf->lines)
			k++;
	}
	projection(fdf);
}

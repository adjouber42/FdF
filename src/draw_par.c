/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_par.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 15:36:56 by adjouber          #+#    #+#             */
/*   Updated: 2018/12/20 15:07:31 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	projection_par(t_fdf *fdf)
{
	int	i;

	i = 0;
	if (!(fdf->coorf = ft_memalloc(sizeof(t_coorf) * fdf->lines * fdf->points)))
		return ;
	while (i < fdf->lines * fdf->points)
	{
		fdf->coorf[i].x = (float)fdf->coord[i].x * 50
			+ (float)fdf->coord[i].z * 2.5;
		fdf->coorf[i].y = (float)fdf->coord[i].y * 50
			+ (float)fdf->coord[i].z * 1.25;
		i++;
	}
	display(fdf);
}

void		draw_par(t_fdf *fdf)
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
	projection_par(fdf);
}

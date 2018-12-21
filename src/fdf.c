/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 12:28:26 by adjouber          #+#    #+#             */
/*   Updated: 2018/12/21 18:33:04 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	projection_bis(int key, t_fdf *fdf)
{
	if (key == 35 && fdf->projection != 2)
	{
		ft_bzero(fdf->data, LON * HAU * 4);
		fdf->projection = 2;
		draw(fdf);
	}
	if (key == 34 && fdf->projection != 1)
	{
		ft_bzero(fdf->data, LON * HAU * 4);
		fdf->projection = 1;
		draw(fdf);
	}
}

int		keyboard(int key, t_fdf *fdf)
{
	if (key == 53)
		exit(EXIT_SUCCESS);
	projection_bis(key, fdf);
	keyboard_max(key, fdf);
	return (0);
}

void	ft_fdf(t_fdf *fdf)
{
	if (!(fdf->img = mlx_new_image(fdf->mlx, LON, HAU)))
	{
		ft_putendl("manque de place pour new_image");
		exit(0);
	}
	if (!(fdf->data = mlx_get_data_addr(fdf->img, &fdf->bpp,
					&fdf->size_line, &fdf->endian)))
	{
		ft_putendl("manque de place pour data_addr");
		exit(0);
	}
}

void	mlx(t_fdf *fdf, char *av)
{
	fdf->coef = 1;
	fdf->projection = 2;
	if (!(fdf->mlx = mlx_init()))
	{
		ft_putendl("manque de place pour mlx_init");
		exit(0);
	}
	fdf->win = mlx_new_window(fdf->mlx, LON, HAU, ft_strjoin("Fdf - ", av));
	ft_fdf(fdf);
	draw(fdf);
	mlx_hook(fdf->win, 2, 1L << 1, keyboard, fdf);
	mlx_loop(fdf->mlx);
}

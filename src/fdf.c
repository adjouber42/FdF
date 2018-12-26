/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 12:28:26 by adjouber          #+#    #+#             */
/*   Updated: 2018/12/26 13:04:57 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		keyboard(int key, t_fdf *fdf)
{
	if (key == 53)
		exit(EXIT_SUCCESS);
	if (key == 35 && fdf->projection != 2)
	{
		ft_bzero(fdf->data, LON * HAU * 4);
		fdf->projection = 2;
		draw(fdf);
		commande(fdf);
	}
	if (key == 34 && fdf->projection != 1)
	{
		ft_bzero(fdf->data, LON * HAU * 4);
		fdf->projection = 1;
		draw(fdf);
		commande(fdf);
	}
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

void	commande(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx, fdf->win, 35, 35, 0xFFFFFF, "isometrie = i");
	mlx_string_put(fdf->mlx, fdf->win, 35, 55, 0xFFFFFF, "parallele = p");
	mlx_string_put(fdf->mlx, fdf->win, 35, 75, 0xFFFFFF,
			"move = up , down , left , right");
	mlx_string_put(fdf->mlx, fdf->win, 35, 95, 0xFFFFFF, "zoom = + , -");
	mlx_string_put(fdf->mlx, fdf->win, 35, 115, 0xFFFFFF, "altitude = < , >");
	mlx_string_put(fdf->mlx, fdf->win, 35, 135, 0xFFFFFF,
			"change color = r , v , b");
	mlx_string_put(fdf->mlx, fdf->win, 35, 155, 0xFFFFFF, "reset = space");
	mlx_string_put(fdf->mlx, fdf->win, 35, 175, 0xFFFFFF, "close = esc");
}

void	mlx(t_fdf *fdf, char *av)
{
	fdf->coef = 1;
	fdf->projection = 2;
	rouge(fdf);
	fdf->zoom = LON / (fdf->points + fdf->lines);
	if (!(fdf->mlx = mlx_init()))
	{
		ft_putendl("manque de place pour mlx_init");
		exit(0);
	}
	fdf->win = mlx_new_window(fdf->mlx, LON, HAU, ft_strjoin("Fdf - ", av));
	ft_fdf(fdf);
	draw(fdf);
	commande(fdf);
	mlx_hook(fdf->win, 2, 1L << 1, keyboard, fdf);
	mlx_loop(fdf->mlx);
}

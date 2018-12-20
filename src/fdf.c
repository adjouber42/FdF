/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 12:28:26 by adjouber          #+#    #+#             */
/*   Updated: 2018/12/20 17:15:50 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	projection(int key, t_fdf *fdf)
{
	if (key == 84 && fdf->projection != 2)
	{
		fdf->projection = 2;
		fdf->zoom_limit = 1;
		mlx_clear_window(fdf->mlx, fdf->win);
		draw_par(fdf);
	}
	if (key == 83 && fdf->projection != 1)
	{
		fdf->projection = 1;
		fdf->zoom_limit = 1;
		mlx_clear_window(fdf->mlx, fdf->win);
		draw_iso(fdf);
	}
}

int		keyboard(int key, t_fdf *fdf)
{
	if (key == 53)
		exit(EXIT_SUCCESS);
	projection(key, fdf);
	if (fdf->projection == 1)
		keyboard_iso(key, fdf);
	if (fdf->projection == 2)
		keyboard_par(key, fdf);
	return (0);
}

void	mlx(t_fdf *fdf, char *av)
{
	fdf->check = 0;
	fdf->zoom_limit = 1;
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, LON, HAU, ft_strjoin("Fdf - ", av));
	draw_par(fdf);
	mlx_key_hook(fdf->win, keyboard, fdf);
	mlx_loop(fdf->mlx);
}

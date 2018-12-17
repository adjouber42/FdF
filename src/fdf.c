/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 12:28:26 by adjouber          #+#    #+#             */
/*   Updated: 2018/12/13 18:10:08 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom(int key, t_fdf *fdf)
{
	if (key == 69)
	{
		if (fdf->color_limit != 4)
		{
			mlx_clear_window(fdf->mlx, fdf->win);
			fdf->sx *= 2;
			fdf->sy *= 2;
			fdf->z *= 2;
			fdf->color_limit++;
			draw(fdf);
		}
	}
	if (key == 78)
	{
		if (fdf->color_limit != 0)
		{
			mlx_clear_window(fdf->mlx, fdf->win);
			fdf->sx /= 2;
			fdf->sy /= 2;
			fdf->z /= 2;
			fdf->color_limit--;
			draw(fdf);
		}
	}
}

void	decal(int key, t_fdf *fdf)
{
	if ((key >= 123 && key <= 126) || key == 49)
	{
		mlx_clear_window(fdf->mlx, fdf->win);
		if (key == 123)
			fdf->dx -= 10;
		if (key == 124)
			fdf->dx += 10;
		if (key == 125)
			fdf->dy += 10;
		if (key == 126)
			fdf->dy -= 10;
		if (key == 49)
			fdf->check = 0;
		draw(fdf);
	}
}

int		keyboard(int key, t_fdf *fdf)
{
	if (key == 53)
		exit(EXIT_SUCCESS);
	if (key == 69 || key == 78)
		zoom(key, fdf);
	decal(key, fdf);
	if (key == 15 && fdf->color.color_set != 0)
	{
		mlx_clear_window(fdf->mlx, fdf->win);
		red(fdf);
		draw(fdf);
	}
	if (key == 11 && fdf->color.color_set != 1)
	{
		mlx_clear_window(fdf->mlx, fdf->win);
		blue(fdf);
		draw(fdf);
	}
	if (key == 9 && fdf->color.color_set != 2)
	{
		mlx_clear_window(fdf->mlx, fdf->win);
		green(fdf);
		draw(fdf);
	}
	return (0);
}

void	mlx(t_fdf *fdf, char *av)
{
	fdf->check = 0;
	fdf->color_limit = 1;
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, LON, HAU, ft_strjoin("Fdf - ", av));
	draw(fdf);
	mlx_key_hook(fdf->win, keyboard, fdf);
	mlx_loop(fdf->mlx);
}

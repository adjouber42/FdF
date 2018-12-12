/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 12:28:26 by adjouber          #+#    #+#             */
/*   Updated: 2018/12/12 14:49:59 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		keyboard(int key, t_fdf *fdf)
{
	(void)fdf;
	if (key == 53)
		exit(EXIT_SUCCESS);
	return (0);
}

void	mlx(t_fdf *fdf, char *av)
{
	fdf->check = 0;
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, LON, HAU, ft_strjoin("Fdf - ", av));
	draw(fdf);
	mlx_key_hook(fdf->win, keyboard, fdf);
	mlx_loop(fdf->mlx);
}

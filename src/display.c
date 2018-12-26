/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 16:06:49 by adjouber          #+#    #+#             */
/*   Updated: 2018/12/26 13:05:32 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	pixel_put_image(int x, int y, t_fdf *fdf, int color)
{
	int	pixel;

	pixel = x * 4 + y * fdf->size_line;
	if (pixel < 0 || pixel > LON * HAU * 4)
		return ;
	fdf->data[pixel] = color & 0xFF;
	fdf->data[pixel + 1] = color >> 8 & 0xFF;
	fdf->data[pixel + 2] = color >> 16 & 0xFF;
}

static void	ft_draw_line2(t_calc *calc, t_fdf *fdf, int i, int k)
{
	int	j;
	int	x;
	int	y;

	j = 1;
	x = fdf->coorf[i].x;
	y = fdf->coorf[i].y;
	calc->cumul = calc->rx / 2;
	while (j <= calc->rx)
	{
		x += calc->xinc;
		calc->cumul += calc->ry;
		if (calc->cumul >= calc->rx)
		{
			calc->cumul -= calc->rx;
			y += calc->yinc;
		}
		if (fdf->dx + x >= 0 && fdf->dx + x < LON &&
				200 + y >= 0 && 200 + y < HAU)
			pixel_put_image(fdf->dx + x, 200 + y, fdf, color(fdf, i, k, j));
		j++;
	}
}

static void	ft_draw_line3(t_calc *calc, t_fdf *fdf, int i, int k)
{
	int	j;
	int	x;
	int	y;

	j = 1;
	x = fdf->coorf[i].x;
	y = fdf->coorf[i].y;
	calc->cumul = calc->ry / 2;
	while (j <= calc->ry)
	{
		y += calc->yinc;
		calc->cumul += calc->rx;
		if (calc->cumul >= calc->ry)
		{
			calc->cumul -= calc->ry;
			x += calc->xinc;
		}
		if (fdf->dx + x >= 0 && fdf->dx + x < LON &&
				200 + y >= 0 && 200 + y < HAU)
			pixel_put_image(fdf->dx + x, 200 + y, fdf, color(fdf, i, k, j));
		j++;
	}
}

static void	ft_draw_line1(t_fdf *fdf, int i, int k)
{
	t_calc	*calc;
	int		j;

	j = 1;
	if (!(calc = ft_memalloc(sizeof(t_calc))))
		return ;
	calc->rx = fdf->coorf[k].x - fdf->coorf[i].x;
	calc->ry = fdf->coorf[k].y - fdf->coorf[i].y;
	calc->xinc = (calc->rx >= 0) ? 1 : -1;
	calc->yinc = (calc->ry >= 0) ? 1 : -1;
	calc->rx = (calc->rx >= 0) ? calc->rx : -calc->rx;
	calc->ry = (calc->ry >= 0) ? calc->ry : -calc->ry;
	if (calc->rx >= calc->ry)
		ft_draw_line2(calc, fdf, i, k);
	else
		ft_draw_line3(calc, fdf, i, k);
	free(calc);
	calc = NULL;
}

void		display(t_fdf *fdf)
{
	int i;

	i = 0;
	while (i < fdf->lines * fdf->points)
	{
		if ((i + 1) % fdf->points != 0)
			ft_draw_line1(fdf, i, i + 1);
		if (i < (fdf->lines - 1) * fdf->points)
			ft_draw_line1(fdf, i, i + fdf->points);
		i++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:25:16 by adjouber          #+#    #+#             */
/*   Updated: 2018/12/17 15:05:33 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "get_next_line.h"
# include "mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# define LON 1500
# define HAU 1500

typedef struct		s_color
{
	int				color_set;
	unsigned long	color1;
	unsigned long	color2;
	unsigned long	color3;
	unsigned long	color4;
	unsigned long	color5;
	unsigned long	color6;
	unsigned long	color7;
	unsigned long	color8;
	unsigned long	color9;
}					t_color;

typedef struct		s_fdf
{
	int				fd;
	char			*file;
	void			*mlx;
	void			*win;
	int				**map;
	int				lines;
	int				points;
	int				check;
	int				z;
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				max;
	int				min;
	int				*pixel_color;
	t_color			color;
	unsigned long	color_put;
	int				color_limit;
}					t_fdf;

int					ft_read(t_fdf *fdf);
void				mlx(t_fdf *fdf, char *av);
void				draw(t_fdf *fdf);
void				red(t_fdf *fdf);
void				blue(t_fdf *fdf);
void				green(t_fdf *fdf);
void				color(t_fdf *fdf, int x, int y);

#endif

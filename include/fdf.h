/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:25:16 by adjouber          #+#    #+#             */
/*   Updated: 2018/12/20 17:10:23 by adjouber         ###   ########.fr       */
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
# define LON 2000
# define HAU 1300

typedef struct		s_calc
{
	int				xinc;
	int				yinc;
	int				rx;
	int				ry;
	int				cumul;
}					t_calc;

typedef struct		s_coord
{
	int				x;
	int				y;
	int				z;
}					t_coord;

typedef struct		s_coorf
{
	float			x;
	float			y;
}					t_coorf;

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
	t_coord			*coord;
	t_coorf			*coorf;
	int				zoom_limit;
	int				projection;
}					t_fdf;

int					ft_read(t_fdf *fdf);
void				mlx(t_fdf *fdf, char *av);
void				draw_iso(t_fdf *fdf);
int					color_par(t_fdf *fdf, int i, int j, int k);
void				draw_par(t_fdf *fdf);
void				display(t_fdf *fdf);
void				keyboard_iso(int key, t_fdf *fdf);
void				keyboard_par(int key, t_fdf *fdf);

#endif

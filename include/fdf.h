/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:25:16 by adjouber          #+#    #+#             */
/*   Updated: 2019/03/06 14:38:24 by adjouber         ###   ########.fr       */
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
	int				coef;
	int				zoom;
	int				dx;
	t_coord			*coord;
	t_coorf			*coorf;
	int				color;
	int				color_set;
	int				color_mult;
	int				fin;
	void			*img;
	char			*data;
	int				bpp;
	int				endian;
	int				size_line;
	int				projection;
}					t_fdf;

int					ft_read(t_fdf *fdf);
void				mlx(t_fdf *fdf);
int					color(t_fdf *fdf, int i, int j, int k);
void				draw(t_fdf *fdf);
void				display(t_fdf *fdf);
void				keyboard_max(int key, t_fdf *fdf);
void				projection(t_fdf *fdf);
void				rouge(t_fdf *fdf);
void				vert(t_fdf *fdf);
void				bleu(t_fdf *fdf);
void				commande(t_fdf *fdf);
void				ft_free(t_fdf *fdf);

#endif

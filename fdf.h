/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:25:16 by adjouber          #+#    #+#             */
/*   Updated: 2018/12/12 14:16:51 by adjouber         ###   ########.fr       */
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
	unsigned long	color;
}					t_fdf;

int		ft_read(t_fdf *x);
void	mlx(t_fdf *x, char *av);
void	draw(t_fdf *x);

#endif

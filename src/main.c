/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:27:28 by adjouber          #+#    #+#             */
/*   Updated: 2018/12/26 15:04:21 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

static void	start(t_fdf *fdf, char **av)
{
	if (av[1] == NULL || ft_read(fdf) == -1)
	{
		ft_putendl("Error");
		return ;
	}
	fdf->size_line = 0;
	fdf->endian = 0;
	fdf->bpp = 0;
	fdf->img = NULL;
	fdf->data = NULL;
	mlx(fdf, av[1]);
}

static int	ft_print_usage(void)
{
	ft_putendl("usage: ./fdf input_file");
	return (0);
}

static void	ft_free(t_fdf fdf)
{
	free(fdf.file);
	free(fdf.coord);
	free(fdf.coorf);
	free(fdf.data);
	free(fdf.map);
}

int			main(int ac, char **av)
{
	t_fdf	fdf;

	if (ac != 2)
		return (ft_print_usage());
	fdf.file = av[1];
	fdf.fd = open(fdf.file, O_RDONLY);
	start(&fdf, av);
	ft_free(fdf);
	return (0);
}

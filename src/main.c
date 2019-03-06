/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:27:28 by adjouber          #+#    #+#             */
/*   Updated: 2019/03/06 14:43:03 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

static int	start(t_fdf *fdf, char **av)
{
	if (av[1] == NULL || ft_read(fdf) == -1)
	{
		ft_putendl("Error");
		return (0);
	}
	fdf->size_line = 0;
	fdf->endian = 0;
	fdf->bpp = 0;
	fdf->img = NULL;
	fdf->data = NULL;
	mlx(fdf);
	return (1);
}

static int	ft_print_usage(void)
{
	ft_putendl("usage: ./fdf input_file");
	return (0);
}

void	ft_free(t_fdf *fdf)
{
	int	i;

	i = 0;
	while (i < fdf->lines)
	{
		free(fdf->map[i]);
		i++;
	}
	free(fdf->map);
	free(fdf->coord);
}

int			main(int ac, char **av)
{
	t_fdf	fdf;

	if (ac != 2)
		return (ft_print_usage());
	fdf.file = av[1];
	fdf.fd = open(fdf.file, O_RDONLY);
	if (start(&fdf, av) == 0)
		return (0);
	return (0);
}

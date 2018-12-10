/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:27:28 by adjouber          #+#    #+#             */
/*   Updated: 2018/12/10 17:03:48 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

static int	ft_print_error(void)
{
	ft_putendl("error");
	return (0);
}

static int	ft_print_usage(void)
{
	ft_putendl("usage: ./fdf input_file");
	return (0);
}

static int	exit_key(int key, void *param)
{
	(void)param;
	if (key == 53)
		exit(EXIT_SUCCESS);
	return (0);
}

int			main(int ac, char **av)
{
	t_fdf	x;

	if (ac != 2)
		return (ft_print_usage());
	x.file = av[1];
	x.fd = open(x.file, O_RDONLY);
	if (!(ft_read(x)))
		return (ft_print_error());
	x.mlx_ptr = mlx_init();
	x.win_ptr = mlx_new_window (x.mlx_ptr, 500, 500, "FdF");
	mlx_key_hook(x.win_ptr, exit_key, (void*)0);
	mlx_loop(x.mlx_ptr);
}

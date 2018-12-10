/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:27:28 by adjouber          #+#    #+#             */
/*   Updated: 2018/12/10 13:52:27 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

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
	void	*mlx_ptr;
	void	*win_ptr;
	(void)av;
	if (ac != 2)
		return (ft_print_usage());
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window (mlx_ptr, 500, 500, "FdF");
	mlx_key_hook(win_ptr, exit_key, (void*)0);
	mlx_loop(mlx_ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 13:41:40 by adjouber          #+#    #+#             */
/*   Updated: 2018/12/10 17:05:03 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		check_line(char *tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		if (ft_isdigit(tab[i]) == 0)
			if (tab[i] != '-')
				return (-1);
		i++;
	}
	return (0);
}

int		mp_count(t_fdf *x, char *line)
{
	int		i;
	char	**tab;

	i = 0;
	tab = ft_strsplit(line, ' ');
	while (tab[i])
	{
		if (check_line(tab[i]) == -1)
			return (-1);
		free(tab[i]);
		i++;
	}
	if (x->lines == 0)
		x->points = i;
	else
	{
		if (i != x->points)
			return (-1);
	}
	free(line);
	free(tab);
	x->lines++;
	return(0);
}

int		alloc_map(t_fdf *x)
{
	char	*line;
	int		ret;

	line = NULL;
	while ((ret = get_next_line(x->fd, &line)) > 0)
		if (mp_count(x, line) == -1)
			return (-1);
	if (!(x->map = ft_memalloc(sizeof(int*) * x->lines)))
		return (-1);
	close(x->fd);
	x->fd = open(x->file, O_RDONLY);
	return (0);
}

int		ft_read(t_fdf *x)
{
	char	*line;
	char	**tab;
	int		xy[3];

	xy[1] = 0;
	if (!(alloc_map(x)))
		return (-1);
	while ((xy[2] = get_next_line(x->fd, &line)) > 0)
	{
		xy[0] = 0;
		tab = ft_strsplit(line, ' ');
		if (!(x->map[xy[1]] = ft_memalloc(sizeof(int) * x->points)))
			return (-1);
		while (tab[xy[0]])
		{
			x->map[xy[1]][xy[0]] = ft_atoi(tab[xy[0]]);
			free(tab[xy[0]]);
			xy[0]++;
		}
		free(tab);
		xy[1]++;
	}
	return ((xy[2] == -1) ? -1 : 0);
}

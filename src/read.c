/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 13:41:40 by adjouber          #+#    #+#             */
/*   Updated: 2018/12/21 14:29:21 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	check_line(char *tab)
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

static int	mp_count(t_fdf *fdf, char *line)
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
	if (fdf->lines == 0)
		fdf->points = i;
	else
	{
		if (i != fdf->points)
			return (-1);
	}
	free(line);
	free(tab);
	fdf->lines++;
	return (0);
}

static int	alloc_map(t_fdf *fdf)
{
	char	*line;
	int		ret;

	line = NULL;
	fdf->lines = 0;
	while ((ret = get_next_line(fdf->fd, &line)) > 0)
		if (mp_count(fdf, line) == -1)
			return (-1);
	if (ret == 0 && line == NULL)
		return (-1);
	if (!(fdf->map = ft_memalloc(sizeof(int*) * fdf->lines)))
		return (-1);
	close(fdf->fd);
	fdf->fd = open(fdf->file, O_RDONLY);
	return (0);
}

int			ft_read(t_fdf *fdf)
{
	char	*line;
	char	**tab;
	int		xy[3];

	xy[1] = 0;
	if (alloc_map(fdf) == -1)
		return (-1);
	while ((xy[2] = get_next_line(fdf->fd, &line)) > 0)
	{
		xy[0] = 0;
		tab = ft_strsplit(line, ' ');
		if (!(fdf->map[xy[1]] = ft_memalloc(sizeof(int) * fdf->points)))
			return (-1);
		while (tab[xy[0]])
		{
			fdf->map[xy[1]][xy[0]] = ft_atoi(tab[xy[0]]);
			free(tab[xy[0]]);
			xy[0]++;
		}
		free(tab);
		xy[1]++;
	}
	return ((xy[2] == -1) ? -1 : 0);
}

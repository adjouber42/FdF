/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:40:10 by adjouber          #+#    #+#             */
/*   Updated: 2018/11/07 11:40:14 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*zone_memoire;

	zone_memoire = malloc(size);
	if (zone_memoire)
	{
		ft_bzero(zone_memoire, size);
		return (zone_memoire);
	}
	else
		return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:42:07 by adjouber          #+#    #+#             */
/*   Updated: 2018/11/09 13:16:55 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*d;

	i = 0;
	d = (unsigned char *)b;
	while (i < n)
		d[i++] = (unsigned char)c;
	b = (void *)d;
	return (b);
}

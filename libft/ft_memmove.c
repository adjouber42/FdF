/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:41:58 by adjouber          #+#    #+#             */
/*   Updated: 2018/11/09 13:16:14 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*sdst;
	unsigned char	*ssrc;

	i = 0;
	sdst = (unsigned char *)dst;
	ssrc = (unsigned char *)src;
	if (sdst > ssrc)
		while (i < n)
		{
			sdst[n - 1] = ssrc[n - 1];
			n--;
		}
	else
		while (i < n)
		{
			sdst[i] = ssrc[i];
			i++;
		}
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:41:35 by adjouber          #+#    #+#             */
/*   Updated: 2018/11/09 13:10:01 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ssrc;
	unsigned char	*sdst;

	ssrc = (unsigned char *)src;
	sdst = (unsigned char *)dst;
	while (n > 0)
	{
		*sdst++ = *ssrc++;
		n--;
	}
	return (dst);
}

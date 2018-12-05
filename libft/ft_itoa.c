/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:37:17 by adjouber          #+#    #+#             */
/*   Updated: 2018/11/07 14:13:59 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_str(long i)
{
	int	len;

	len = 1;
	if (i < 0)
		i = i * -1;
	while (i >= 10)
	{
		i = i / 10;
		len++;
	}
	return (len);
}

static char	*filled_str(char *str, long i, int len)
{
	int		start;

	str[len] = '\0';
	len = len - 1;
	if (i < 0)
	{
		i = i * -1;
		start = 1;
		str[0] = '-';
	}
	else
		start = 0;
	while (len >= start)
	{
		str[len] = i % 10 + '0';
		i = i / 10;
		len--;
	}
	return (str);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	i;

	i = n;
	len = len_str(i);
	if (i < 0)
		len = len + 1;
	str = ft_strnew(len);
	if (!str)
		return (NULL);
	str = filled_str(str, i, len);
	return (str);
}

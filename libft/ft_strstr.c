/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:44:41 by adjouber          #+#    #+#             */
/*   Updated: 2018/11/09 16:24:47 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char const *str, char const *to_find)
{
	int	i;
	int	n;
	int	tmp;

	i = 0;
	n = 0;
	if (!to_find[n])
		return ((char*)str);
	while (str[i])
	{
		tmp = i;
		while (str[tmp] && str[tmp] == to_find[n])
		{
			tmp++;
			n++;
			if (to_find[n] == '\0')
				return ((char*)(str + i));
		}
		i++;
		n = 0;
	}
	return (0);
}

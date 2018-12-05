/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:44:11 by adjouber          #+#    #+#             */
/*   Updated: 2018/11/07 11:44:12 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	int		j;
	char	*pt;

	i = 0;
	pt = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		if (big[i] == little[0])
		{
			pt = (char *)big + i;
			j = 0;
			while (big[i + j] == little[j] && i + j < len)
			{
				if (little[j + 1] == '\0')
					return (pt);
				j++;
			}
			pt = 0;
		}
		i++;
	}
	return (NULL);
}

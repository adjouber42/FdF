/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 14:54:14 by adjouber          #+#    #+#             */
/*   Updated: 2018/11/14 15:59:50 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		i;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	if (!(str = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	i = 0;
	len = 0;
	while (s1[i])
	{
		str[len] = s1[i];
		i++;
		len++;
	}
	i = 0;
	while (s2[i])
	{
		str[len] = s2[i];
		i++;
		len++;
	}
	str[len] = '\0';
	return (str);
}

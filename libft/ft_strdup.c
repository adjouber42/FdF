/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:43:18 by adjouber          #+#    #+#             */
/*   Updated: 2018/11/07 14:00:57 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *s)
{
	char	*cpy;

	if (!(cpy = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	cpy = ft_strcpy(cpy, s);
	return (cpy);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:39:28 by adjouber          #+#    #+#             */
/*   Updated: 2018/11/14 15:52:29 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_start(char const *s)
{
	unsigned int	i;
	unsigned int	start;

	i = 0;
	start = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
	{
		i++;
		start++;
	}
	return (start);
}

static int	ft_end(char const *s)
{
	unsigned int	i;
	unsigned int	end;

	end = ft_strlen(s);
	i = end - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		i--;
		end--;
	}
	return (end);
}

char		*ft_strtrim(char const *s)
{
	char			*str;
	unsigned int	i;
	unsigned int	start;
	unsigned int	end;

	i = 0;
	if (!s)
		return (NULL);
	start = ft_start(s);
	if (start == ft_strlen(s))
		return (ft_strdup(""));
	end = ft_end(s);
	if (!(str = ft_strnew(end - start)))
		return (NULL);
	i = 0;
	while (start < end)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

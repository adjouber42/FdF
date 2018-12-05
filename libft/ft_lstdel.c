/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjouber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:14:27 by adjouber          #+#    #+#             */
/*   Updated: 2018/11/13 11:15:12 by adjouber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*a_effacer;
	t_list	*prochain_maillon;

	a_effacer = *alst;
	while (a_effacer)
	{
		prochain_maillon = a_effacer->next;
		del(a_effacer->content, a_effacer->content_size);
		free(a_effacer);
		a_effacer = prochain_maillon;
	}
	*alst = NULL;
}

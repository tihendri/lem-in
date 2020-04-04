/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 09:51:09 by tihendri          #+#    #+#             */
/*   Updated: 2019/06/28 13:00:52 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**Adds the element new at the beginning of the list.
**Arrow shows the reference inside the current block of the list.
**next (line 25) points to a pointer to alst,
**then (line 26) the pointer to alst points to a new list,
**thus a new list has been added.
*/

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (*alst != NULL)
		new->next = *alst;
	*alst = new;
}

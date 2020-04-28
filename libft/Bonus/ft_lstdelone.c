/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 12:01:59 by tihendri          #+#    #+#             */
/*   Updated: 2019/06/12 13:44:56 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**Takes as a parameter a link’s pointer address and frees the memory of the
**link’s content using the function del given as a parameter,
**then frees the link’s memory using free(3).
**The memory of next must not be freed under any circumstance.
**Finally, the pointer to the link that was just freed must be set to NULL.
*/

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (alst && del)
	{
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = NULL;
	}
}

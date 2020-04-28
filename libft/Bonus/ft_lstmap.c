/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 12:25:12 by tihendri          #+#    #+#             */
/*   Updated: 2019/06/12 14:26:03 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**Iterates a list lst and applies the function f to each link to create a
**“fresh” list malloc resulting from the successive applications of f.
**If the allocation fails, the function returns NULL.
*/

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*result;

	if (lst)
	{
		result = f(lst);
		result->next = ft_lstmap(lst->next, f);
		return (result);
	}
	return (NULL);
}

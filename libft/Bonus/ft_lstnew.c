/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 11:34:49 by tihendri          #+#    #+#             */
/*   Updated: 2019/06/12 15:29:41 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**Allocates (with malloc(3)) and returns a “fresh” link.
**The variables content and content_size of the new link are initialized by
**copy of the parameters of the function.
**If the parameter content is nul, the variable content is initialized to NULL
**and the variable content_size is initialized to 0 even if the parameter
**content_size isn’t.
**The variable next is initialized to NULL.
**If the allocation fails, the function returns NULL.
*/

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*fresh;

	fresh = (t_list *)ft_memalloc(sizeof(*fresh));
	if (!fresh)
		return (NULL);
	if (!content)
	{
		fresh->content = NULL;
		fresh->content_size = 0;
	}
	else
	{
		fresh->content_size = content_size;
		fresh->content = ft_memalloc(content_size);
		if (!fresh->content)
		{
			free(fresh);
			return (NULL);
		}
		fresh->content = ft_memcpy(fresh->content, content, content_size);
	}
	fresh->next = NULL;
	return (fresh);
}

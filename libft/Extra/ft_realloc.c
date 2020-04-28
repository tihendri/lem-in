/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 11:45:46 by tihendri          #+#    #+#             */
/*   Updated: 2019/06/24 12:25:29 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**allocates memory that can be used by any data type.
**tries to change the size of the allocation pointed to by ptr to size,
**and returns ptr.
**If there is not enough room to enlarge the memory allocation, ft_realloc()
**creates a new allocation, copies as much of the old data pointed to by ptr
**as will fit to the new allocation, frees the old allocation, and returns a
**pointer to the allocated memory.
**If ptr is NULL, function identical to a call to malloc() for size bytes.
**If size is zero and ptr is not NULL, a new, minimum sized object is allocated
**and the original object is freed.
*/

void	*ft_realloc(void *ptr, size_t size)
{
	char *new;

	new = (char *)malloc(size);
	ft_bzero(new, size);
	ft_memcpy(new, ptr, ft_strlen(ptr) + 1);
	free(ptr);
	return (new);
}

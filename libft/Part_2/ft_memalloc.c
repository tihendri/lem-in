/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 12:11:05 by tihendri          #+#    #+#             */
/*   Updated: 2019/06/24 11:43:48 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**allocates memory of a specified size and returns that area of memory.
*/

void	*ft_memalloc(size_t size)
{
	void	*p;

	p = malloc(size);
	if (p == NULL)
	{
		return (NULL);
	}
	ft_bzero(p, size);
	return (p);
}

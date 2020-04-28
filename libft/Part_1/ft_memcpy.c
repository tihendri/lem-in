/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 15:21:35 by tihendri          #+#    #+#             */
/*   Updated: 2019/06/24 11:46:45 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**copies n bytes from memory area src to memory area dst.
**If dst and src overlap, behavior is undefined.
**returns original value of dst
*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	if (dst == NULL && src == NULL)
		return (NULL);
	while (n > 0)
	{
		n--;
		((unsigned char *)dst)[n] = ((unsigned char *)src)[n];
	}
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 09:41:21 by tihendri          #+#    #+#             */
/*   Updated: 2019/06/24 12:09:48 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**copies len bytes from string src to string dst.
**The two strings may overlap, however the copy must be done non-destructively.
**returns the original value of dst.
*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*source;
	unsigned char	*destination;

	source = (unsigned char *)src;
	destination = (unsigned char *)dst;
	if (destination == source)
		return (dst);
	if (source < destination)
	{
		source = (unsigned char *)src + len - 1;
		destination = dst + len - 1;
		while (len--)
		{
			*(destination--) = *(source--);
		}
	}
	else
		while (len--)
		{
			*(destination++) = *(source++);
		}
	return (dst);
}

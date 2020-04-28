/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 15:55:15 by tihendri          #+#    #+#             */
/*   Updated: 2019/06/24 12:03:01 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**copies bytes from string src to string dst.
**If the character c (converted to an unsigned char) occurs in the string src,
**the copy stops and a pointer to the byte after the copy of c in the string dst
**is returned. Otherwise, n bytes are copied, and a NULL pointer is returned.
**src and dst should not overlap, as the behavior is undefined.
**So basically, copies s to d until c in s otherwise copy n bytes.
*/

void	*ft_memccpy(void *d, const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	cc;

	i = 0;
	cc = (unsigned char)c;
	while (i < n)
	{
		((char *)d)[i] = ((char *)s)[i];
		i++;
		if (((unsigned char *)d)[i - 1] == cc)
			return (&((unsigned char *)d)[i]);
	}
	return (NULL);
}

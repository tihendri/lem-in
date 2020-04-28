/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 12:57:02 by tihendri          #+#    #+#             */
/*   Updated: 2019/06/24 13:43:51 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**appends (adds to the end) string src, at most dstsize characters,
**to the end of dst.
*/

size_t			ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		a;
	size_t		b;
	char		*c;
	char		*d;

	c = (char *)src;
	d = dst;
	a = dstsize;
	while (a-- != 0 && *d != '\0')
		d++;
	b = d - dst;
	a = dstsize - b;
	if (a <= 0)
		return (dstsize + ft_strlen(c));
	while (*c != '\0')
	{
		if (a != 1)
		{
			*d++ = *c;
			a--;
		}
		c++;
	}
	*d = '\0';
	return (b + (c - (char *)src));
}

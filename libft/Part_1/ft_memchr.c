/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 10:14:11 by tihendri          #+#    #+#             */
/*   Updated: 2019/06/24 11:52:28 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**locates the first occurrence of c (converted to an unsigned char) in string s.
**returns a pointer to the byte located,
**or NULL if no such byte exists within n bytes.
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*e;

	e = s;
	while (n--)
	{
		if (*e++ == (unsigned char)c)
		{
			return ((void *)--e);
		}
	}
	return (NULL);
}

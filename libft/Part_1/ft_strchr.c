/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 13:55:17 by tihendri          #+#    #+#             */
/*   Updated: 2019/06/24 13:10:49 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**locates the first occurrence of c (converted to a char) in the string pointed
**to by s.
**returns a pointer to the located character, or NULL if the character does
**not appear in the string.
*/

char	*ft_strchr(const char *s, int c)
{
	size_t		n;

	n = 0;
	if (c == 0)
	{
		while (s[n])
		{
			n++;
		}
		return ((char *)s + n);
	}
	while (s[n])
	{
		if (s[n] == c)
		{
			return ((char *)s + n);
		}
		n++;
	}
	return (NULL);
}

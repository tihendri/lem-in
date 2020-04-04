/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 14:43:45 by tihendri          #+#    #+#             */
/*   Updated: 2019/06/24 14:25:00 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**Locates the last occurrence of c (converted to a char) in the string pointed
**to by s.
**The terminating null character is considered to be part of the string;
**therefore if c is `\0', the functions locate the terminating `\0'.
*/

char	*ft_strrchr(const char *s, int c)
{
	int n;

	n = ft_strlen(s);
	while (n >= 0)
	{
		if (s[n] == (int)c)
		{
			return ((char *)(s + n));
		}
		n--;
	}
	return (NULL);
}

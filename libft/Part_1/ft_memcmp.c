/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 10:42:15 by tihendri          #+#    #+#             */
/*   Updated: 2019/06/24 11:55:31 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**compares byte string s1 against byte string s2.
**Both strings are assumed to be n bytes long.
**returns zero if the two strings are identical,
**otherwise returns the difference between the first two differing bytes.
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*string1;
	const unsigned char	*string2;

	if (n == 0 || s1 == s2)
	{
		return (0);
	}
	string1 = (const unsigned char *)s1;
	string2 = (const unsigned char *)s2;
	while (n--)
	{
		if (*string1 != *string2)
		{
			return (*string1 - *string2);
		}
		if (n)
		{
			string1++;
			string2++;
		}
	}
	return (0);
}

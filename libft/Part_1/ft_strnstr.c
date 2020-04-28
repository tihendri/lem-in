/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 15:04:29 by tihendri          #+#    #+#             */
/*   Updated: 2019/06/24 14:20:45 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**Locates the first occurrence of the null-terminated string needle
**in the string haystack, where not more than len characters are searched.
**Characters that appear after a `\0' character are not searched.
*/

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t		t;
	size_t		count;

	if (n[0] == '\0')
	{
		return ((char *)h);
	}
	t = 0;
	while (t < len && h[t] != '\0')
	{
		if (h[t] == n[0])
		{
			count = 1;
			while (n[count] != '\0'
					&& h[t + count] == n[count]
					&& (t + count) < len)
			{
				count++;
			}
			if (n[count] == '\0')
				return ((char *)&h[t]);
		}
		t++;
	}
	return (0);
}

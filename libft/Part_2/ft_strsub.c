/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 14:43:20 by tihendri          #+#    #+#             */
/*   Updated: 2019/06/24 14:42:37 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**Allocates and returns a “fresh” substring from the string given as argument.
**The substring begins at index start and is of size len.
**If start and len aren’t refering to a valid substring,
**the behavior is undefined.
**If the allocation fails, the function returns NULL.
*/

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	n;
	char			*string;

	n = 0;
	string = (char *)malloc(sizeof(char) * len + 1);
	if (s)
	{
		if (string == NULL)
			return (NULL);
		while (n < len)
		{
			string[n] = s[start + n];
			n++;
		}
	}
	string[n] = '\0';
	return (string);
}

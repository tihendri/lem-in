/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 11:32:59 by tihendri          #+#    #+#             */
/*   Updated: 2019/06/24 13:24:17 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**allocates sufficient memory for a copy of the string s1, does the copy, and
**returns a pointer to it.
**If insufficient memory is available, NULL is returned.
*/

char	*ft_strdup(const char *s1)
{
	char	*newstring;
	char	*n;
	char	*length;

	newstring = (char *)malloc(ft_strlen(s1) + 1);
	if (newstring == NULL)
		return (NULL);
	n = (char *)s1;
	length = newstring;
	while (*n)
	{
		*length++ = *n++;
	}
	*length = '\0';
	return (newstring);
}

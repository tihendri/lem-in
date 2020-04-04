/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 12:16:14 by tihendri          #+#    #+#             */
/*   Updated: 2019/06/24 14:04:59 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**appends (adds to the end of) not more than n characters from s2,
**and then adds a terminating `\0'.
*/

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t count;
	size_t length;

	count = 0;
	length = 0;
	while (s1[length])
	{
		length++;
	}
	while (s2[count] && count < n)
	{
		s1[length + count] = s2[count];
		count++;
	}
	s1[length + count] = '\0';
	return (s1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 13:06:11 by tihendri          #+#    #+#             */
/*   Updated: 2019/06/24 15:00:25 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**compares not more than n characters.
**designed for comparing strings rather than binary data,
**thus characters that appear after a `\0' character are not compared
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	if (n > i)
	{
		if (((unsigned char)s1[i] - (unsigned char)s2[i]) < 0)
			return (-1);
		if (((unsigned char)s1[i] - (unsigned char)s2[i]) > 0)
			return (1);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 16:34:35 by tihendri          #+#    #+#             */
/*   Updated: 2019/06/24 14:10:22 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**copies at most n characters from the string s1,
**and always NUL terminating the copied string.
*/

char	*ft_strndup(const char *s, size_t n)
{
	char *string;

	string = (char *)malloc(sizeof(char) * n + 1);
	if (string == NULL)
	{
		return (NULL);
	}
	string = ft_strncpy(string, s, n);
	string[n] = '\0';
	return (string);
}

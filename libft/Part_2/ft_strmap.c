/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 11:34:28 by tihendri          #+#    #+#             */
/*   Updated: 2019/06/24 14:00:33 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**Applies the function f to each character of the string given
**as argument to create a “fresh” new string (with malloc(3))
**resulting from the successive applications of f.
*/

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	n;
	char			*string;

	if (s && f)
	{
		n = 0;
		string = (char *)malloc(sizeof(char) * (ft_strlen(s)) + 1);
		if (string == NULL)
		{
			return (NULL);
		}
		while (s[n] != '\0')
		{
			string[n] = f(s[n]);
			n++;
		}
		string[n] = '\0';
		return (string);
	}
	return (0);
}

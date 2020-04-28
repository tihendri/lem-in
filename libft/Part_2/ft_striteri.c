/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 11:32:24 by tihendri          #+#    #+#             */
/*   Updated: 2019/06/24 13:34:58 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**Applies the function f to each character of the string passed as argument,
**and passing its index as first argument.
**Each character is passed by address to f to be modified if necessary.
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int n;

	if (s == NULL || f == NULL)
		return ;
	n = 0;
	while (s[n] != '\0')
	{
		f(n, &s[n]);
		n++;
	}
}

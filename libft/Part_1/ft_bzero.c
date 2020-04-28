/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 15:12:56 by tihendri          #+#    #+#             */
/*   Updated: 2019/06/24 12:03:45 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**writes n zeroed bytes to the string s.
**If n is zero, bzero() does nothing.
*/

void	ft_bzero(void *s, size_t n)
{
	char			*z;
	size_t			q;

	z = s;
	q = 0;
	while (q < n)
	{
		((unsigned char *)z)[q] = '\0';
		q++;
	}
	s = z;
}

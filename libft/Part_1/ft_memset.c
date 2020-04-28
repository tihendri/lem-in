/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 12:10:16 by tihendri          #+#    #+#             */
/*   Updated: 2019/06/24 12:12:50 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**writes len bytes of value c (converted to an unsigned char) to the string b.
**returns its first argument
*/

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;
	size_t			n;

	p = b;
	n = 0;
	while (n < len)
	{
		p[n] = c;
		n++;
	}
	return (b);
}

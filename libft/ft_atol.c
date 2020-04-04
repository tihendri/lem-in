/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 10:16:58 by tihendri          #+#    #+#             */
/*   Updated: 2019/07/25 13:00:21 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**Converts the string's ascii values to type long.
**Exactly the same as ft_atoi, the only difference being the return type.
*/

long	ft_atol(const char *s)
{
	long	p;
	int		sign;

	sign = 1;
	p = 0;
	while (*s == '\t' || *s == ' ' || *s == '\n' || *s == '\f'
			|| *s == '\r' || *s == '\v')
		s++;
	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	else if (*s == '+')
		s++;
	while (ft_isdigit(*s))
	{
		p = p * 10 + *s - '0';
		s++;
	}
	return (p * sign);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 15:59:06 by tihendri          #+#    #+#             */
/*   Updated: 2019/07/15 16:08:10 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**Checks whether string passed is a whole number, by iterating through the
**string while ft_isdigit is applied (or not applied) to each character.
*/

int			ft_isnum(char *str)
{
	int n;

	if (!str)
		return (0);
	n = 0;
	while (str[n])
	{
		if (str[n] == '-')
		{
			if (n == 0)
			{
				n++;
				continue ;
			}
			else
				return (0);
		}
		if (!ft_isdigit(str[n]))
			return (0);
		n++;
	}
	return (1);
}

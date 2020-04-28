/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 14:37:24 by tihendri          #+#    #+#             */
/*   Updated: 2019/06/24 13:27:36 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**lexicographically compares two strings.
**If the two srtings are identical, return 1, otherwise return 0.
*/

int	ft_strequ(char const *s1, char const *s2)
{
	if (s1 && s2)
	{
		return (ft_strcmp(s1, s2) ? 0 : 1);
	}
	return (0);
}

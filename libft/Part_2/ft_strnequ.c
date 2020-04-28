/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 14:41:02 by tihendri          #+#    #+#             */
/*   Updated: 2019/06/24 14:12:59 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**Lexicographical comparison between s1 and s2 up to n characters,
**or until a ’\0’ is reached.
**If the 2 strings are identical, the function returns 1, or 0 otherwise.
**Ternary function @line 26.
*/

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (s1 && s2)
	{
		return (ft_strncmp(s1, s2, n) ? 0 : 1);
	}
	return (0);
}

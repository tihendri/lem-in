/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 12:52:49 by tihendri          #+#    #+#             */
/*   Updated: 2019/06/24 13:16:06 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**compare the null-terminated strings s1 and s2.
*/

int		ft_strcmp(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	if (((unsigned char)s1[i] - (unsigned char)s2[i]) < 0)
		return (-1);
	if (((unsigned char)s1[i] - (unsigned char)s2[i]) > 0)
		return (1);
	else
		return (0);
}

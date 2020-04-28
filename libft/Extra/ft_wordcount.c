/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 16:38:52 by tihendri          #+#    #+#             */
/*   Updated: 2019/06/27 17:40:09 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**Counts how many words are in a string.
**The words will be delimited by c.
*/

int	ft_wordcount(char const *s, char c)
{
	size_t	n;
	int		nb_words;
	int		new_word;

	n = 0;
	nb_words = 0;
	new_word = 1;
	while (s[n])
	{
		if (new_word && s[n] != c)
		{
			nb_words++;
			new_word = 0;
		}
		if (s[n] == c)
			new_word = 1;
		n++;
	}
	return (nb_words);
}

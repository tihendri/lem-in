/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 16:35:55 by tihendri          #+#    #+#             */
/*   Updated: 2019/06/28 09:29:35 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**Allocates (with malloc(3)) and returns an array of “fresh” strings
**(all ending with ’\0’, including the array itself) obtained by spliting s
**using the character c as a delimiter.
**If the allocation fails the function returns NULL.
**The functions applied here are ft_count_letters and ft_wordcount.
**When we decifer the prototype this function,
**we find that we need to return a 2D array.
**We first need to seperate the words themselves by using the function
**ft_wordcount, then allocate memory for those words.
**Then we need to get the number of words in each of those words and allocate
**space for them aswell (using ft_strnew in a loop until all words are done).
*/

static char		*ft_get_next_word(char const *s, char c, size_t *start)
{
	size_t	n;

	while (s[*start] == c)
		*start += 1;
	n = *start;
	while (s[*start])
	{
		if (s[*start] == c)
			break ;
		*start += 1;
	}
	return (ft_strsub(s, n, *start - n));
}

char			**ft_strsplit(char const *s, char c)
{
	int		nb_words;
	char	**split;
	size_t	i;
	size_t	start;

	if (!s)
		return (NULL);
	nb_words = ft_wordcount(s, c);
	split = (char **)malloc(sizeof(char *) * (nb_words + 1));
	if (split == NULL)
		return (NULL);
	i = 0;
	start = 0;
	while (nb_words--)
	{
		split[i] = ft_get_next_word(s, c, &start);
		i++;
	}
	split[i] = NULL;
	return (split);
}

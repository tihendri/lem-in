/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 10:55:20 by tihendri          #+#    #+#             */
/*   Updated: 2019/08/12 12:05:22 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list		*ft_lstnew_str(char *content)
{
	t_list	*temp;
	int		i;
	char	*arr;

	if (!(temp = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		temp->content = NULL;
		temp->content_size = 0;
		temp->next = NULL;
		return (temp);
	}
	arr = malloc(sizeof(char) * ft_strlen(content) + 1);
	i = 0;
	while (content[i])
	{
		arr[i] = content[i];
		i++;
	}
	arr[i] = '\0';
	temp->content = (void *)arr;
	temp->next = NULL;
	return (temp);
}

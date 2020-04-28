/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 11:12:04 by tihendri          #+#    #+#             */
/*   Updated: 2019/06/24 13:22:00 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**Frees a string's address and sets it's pointer to NULL.
**I used ft_memdel because it works exactly the same as this function.
*/

void	ft_strdel(char **as)
{
	ft_memdel((void **)as);
}

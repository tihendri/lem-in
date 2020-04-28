/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihendri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 09:55:55 by tihendri          #+#    #+#             */
/*   Updated: 2019/06/12 14:24:07 by tihendri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		n = n * -1;
		ft_putchar_fd('-', fd);
	}
	if (n < 10)
	{
		ft_putchar_fd(n + 48, fd);
		return ;
	}
	ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd((n % 10) + 48, fd);
	return ;
}

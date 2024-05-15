/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgonzal2 <pgonzal2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 21:23:07 by pgonzal2          #+#    #+#             */
/*   Updated: 2024/05/15 21:23:09 by pgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	ft_len(long number)
{
	int	len;

	len = 1;
	if (number < 0)
	{
		number *= -1;
		len++;
	}
	while (number > 9)
	{
		number = number / 10;
		len++;
	}
	return (len);
}

int	ft_putnbr_pf(int n)
{
	int	c;

	c = ft_len(n);
	if (n == -2147483648)
		ft_putstr_pf("-2147483648");
	else
	{
		if (n < 0)
		{
			n *= -1;
			ft_putchar_pf('-');
		}
		if (n > 9)
		{
			ft_putnbr_pf(n / 10);
		}
		ft_putchar_pf((n % 10) + '0');
	}
	return (c);
}

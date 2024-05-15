/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgonzal2 <pgonzal2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 21:23:19 by pgonzal2          #+#    #+#             */
/*   Updated: 2024/05/15 21:23:20 by pgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_c(unsigned long nbr, int *c)
{
	if (nbr >= 16)
	{
		ft_c((nbr / 16), c);
		ft_c((nbr % 16), c);
	}
	if (nbr <= 9)
	{
		ft_putchar_pf((nbr % 10) + '0');
		*c = *c + 1;
	}
	else if (nbr < 16 && nbr > 9)
	{
		ft_putchar_pf(nbr - 10 + 'a');
		*c = *c + 1;
	}
}

int	ft_putnbr_pf_x(unsigned long nbr)
{
	int	c;

	c = 0;
	ft_c(nbr, &c);
	return (c);
}

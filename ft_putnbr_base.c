/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:23:51 by mbentahi          #+#    #+#             */
/*   Updated: 2023/11/28 18:35:49 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(int nbr)
{
	int		i;
	long	nb;
	int counter;
	char *base;
	
	counter = 0;
	base = "013456789abcdef";
	nb = (long)nbr;
	i = ft_strlen(base);
	if (nb < 0)
	{
		counter += ft_putchar('-');
		nb *= -1;
	}
	if (nb >= i)
	{
		counter += ft_putnbr_base(nb / i);
		counter += ft_putnbr_base(nb % i);
	}
	else
		counter += ft_putchar(base[nb]);
	return (counter);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printadd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 20:10:42 by mbentahi          #+#    #+#             */
/*   Updated: 2023/11/28 20:27:24 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putlong_base(unsigned long nb)
{
	unsigned long	i;
	int				counter;
	char			*base;

	counter = 0;
	base = "0123456789abcdef";
	i = ft_strlen(base);
	if (nb >= i)
	{
		counter += ft_putlong_base(nb / i);
		counter += ft_putlong_base(nb % i);
	}
	else
		counter += ft_putchar(base[nb]);
	return (counter);
}

int	ft_printadd(void *s)
{
	unsigned long n;
	// printf("%s\n", (char *)s);
	n = (unsigned long)s;
	return (ft_putlong_base(n));
}
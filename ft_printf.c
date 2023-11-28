/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:42:39 by mbentahi          #+#    #+#             */
/*   Updated: 2023/11/28 18:36:18 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *str,...)
{
	int i;
	int counter;
	va_list varg;
	va_start(varg,str);
	
	counter = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			if (str[i + 1] == '%')
				counter += write(1, "%", 1);
			else if (str[i + 1] == 's')
				counter += ft_putstr(va_arg(varg, char*));
			else if (str[i + 1] == 'd' || str[i + 1] == 'i')
				counter += ft_putnbr(va_arg(varg, int));
			else if (str[i + 1] == 'x')
				counter += ft_putnbr_base(va_arg(varg, int));
		}
		i++;
	}
	return (counter);
}

int main()
{
	printf("%d\n", ft_printf("%x", 123465));
}
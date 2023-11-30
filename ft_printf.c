/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:42:39 by mbentahi          #+#    #+#             */
/*   Updated: 2023/11/30 10:44:48 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		counter;
	va_list	varg;

	va_start(varg, str);
	counter = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			if (str[i + 1] == '%')
				counter += write(1, "%", 1);
			else if (str[i + 1] == 's')
				counter += ft_putstr(va_arg(varg, char *));
			else if (str[i + 1] == 'd' || str[i + 1] == 'i')
				counter += ft_putnbr(va_arg(varg, int));
			else if (str[i + 1] == 'x')
				counter += ft_putnbr_base(va_arg(varg, int), 'x');
			else if (str[i + 1] == 'X')
				counter += ft_putnbr_base(va_arg(varg, int), 'X');
			else if (str[i + 1] == 'p')
			{
				counter += write(1, "0x", 2);
				counter += ft_printadd(va_arg(varg, void *));
			}
			else if (str[i + 1] == 'c')
				counter += write(1, &str[i + 1], 1);
			else
				counter += write(1, &str[i], 1);
			i++;
		}
	}
	return (counter);
}

// int	main(void)
// {
// 	char *p = "12345";
// 	printf("%d\n", ft_printf("%p", p));
// 	printf("%d\n", printf("%p", p));
// }
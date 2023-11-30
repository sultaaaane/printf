#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

size_t	ft_strlen(const char *str);
int		ft_putstr(char *s);
int		ft_printf(const char *str, ...);
int		ft_putnbr(int n);
int		ft_putchar(char c);
int		ft_putnbr_base(int nbr, char c);
int		ft_printadd(void *s);

#endif
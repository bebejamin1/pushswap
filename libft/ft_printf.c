/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeaurai <bbeaurai@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 17:26:53 by bbeaurai          #+#    #+#             */
/*   Updated: 2025/12/15 14:27:22 by bbeaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_printf.h"
# include "Libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <bsd/string.h>
# include <stdio.h>
# include <limits.h>


size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_u_putnbr_b(unsigned long long nbr, char *base)
{
	size_t	nbr_base;
	int		count;

	nbr_base = ft_strlen(base);
	count = 0;
	if (nbr >= nbr_base)
	{
		count += ft_u_putnbr_b((nbr / nbr_base), base);
	}
	nbr = nbr % nbr_base;
	count++;
	write(1, &base[nbr], 1);
	return (count);
}

int	ft_putnbr_base(int nb, char *base)
{
	long	nbr_base;
	long	nbr;
	int		count;

	nbr = nb;
	nbr_base = ft_strlen(base);
	count = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		write(1, "-", 1);
		count++;
	}
	if (nbr >= nbr_base)
	{
		count += ft_putnbr_base((nbr / nbr_base), base);
	}
	nbr = nbr % nbr_base;
	count++;
	write(1, &base[nbr], 1);
	return (count);
}

size_t	for_percent(char c)
{
	write(1, &c, 1);
	return (1);
}

size_t	for_char(int c)
{
	write (1, &c, 1);
	return (1);
}

size_t	for_str(char *str)
{
	size_t	size;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	size = 0;
	while (str[size])
		size++;
	write (1, str, size);
	return (size);
}

size_t	for_address(va_list ap)
{
	unsigned long long	ptr;

	ptr = va_arg(ap, unsigned long long);
	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	return (ft_u_putnbr_b(ptr, "0123456789abcdef") + 2);
}

size_t	check_format(char format, va_list ap)
{
	size_t	length;

	length = 0;
	if (format == '%')
		length = for_percent('%');
	else if (format == 'c')
		length = (for_char(va_arg(ap, int)));
	else if (format == 's')
		length = (for_str(va_arg(ap, char *)));
	else if (format == 'p')
		length = (for_address(ap));
	else if (format == 'd' || format == 'i')
		length = (ft_putnbr_base(va_arg(ap, int), "0123456789"));
	else if (format == 'u')
		length = (ft_u_putnbr_b(va_arg(ap, unsigned int), "0123456789"));
	else if (format == 'x')
		length = (ft_u_putnbr_b(va_arg(ap, unsigned int), "0123456789abcdef"));
	else if (format == 'X')
		length = (ft_u_putnbr_b(va_arg(ap, unsigned int), "0123456789ABCDEF"));
	return (length);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			count = count + check_format(format[++i], ap);
			i++;
		}
		else
		{
			write(1, &format[i++], 1);
			count++;
		}
	}
	va_end(ap);
	return (count);
}

// int	main(void)
// {
// 	ft_printf("x%%x");
// 	printf("\n");	
// 	printf("x%%x");
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf copy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeaurai <bbeaurai@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 17:26:53 by bbeaurai          #+#    #+#             */
/*   Updated: 2025/12/22 11:36:22 by bbeaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

// int	main(void)
// {
// 	ft_printf("x%%x");
// 	printf("\n");	
// 	printf("x%%x");
// }
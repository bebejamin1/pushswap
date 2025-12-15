/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheakers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchy <nbuchy@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 09:46:03 by nbuchy            #+#    #+#             */
/*   Updated: 2025/12/03 17:17:57 by nbuchy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	argv_cheacker(char *str, long nbr)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (!(str[i] >= '0' && str[i] <= '9') && !(str[i] == '-' && (str[i
						+ 1] >= '0' && str[i + 1] <= '9')))
			return (0);
		i++;
	}
	if (str[0] == '-')
		i--;
	if ((nbr > 2147483647 || nbr < -2147483648) || i > 10)
		return (0);
	return (str[0] != '\0');
}

int	checker(long *tab, char **argv, int length)
{
	int	i;
	int	j;

	(void)argv;
	i = 0;
	j = 0;
	if (argv_cheacker(argv[i], tab[i]) == 0)
		return (0);
	while (i < length)
	{
		j = 1;
		while (i + j < length)
		{
			if (tab[i] == tab[i + j] || argv_cheacker(argv[i + j], tab[i
						+ j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

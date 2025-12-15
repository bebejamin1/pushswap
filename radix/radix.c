/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchy <nbuchy@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 09:27:40 by nbuchy            #+#    #+#             */
/*   Updated: 2025/12/03 09:59:06 by nbuchy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	sort_verif(t_list *lst)
{
	t_list	*head1;

	head1 = lst->next;
	while (head1 != NULL)
	{
		if (lst->weight != 0)
		{
			if (lst->content > head1->content)
			{
				return (0);
			}
		}
		head1 = head1->next;
		lst = lst->next;
	}
	return (1);
}

void	transfer_a_b(t_list **a, t_list **b)
{
	while (*b != NULL)
		pa(a, b);
}

void	radix(t_list **a, t_list **b)
{
	int			i;
	int			ptr;
	long long	*nbr;

	i = 0;
	nbr = NULL;
	while (sort_verif(*a) == 0)
	{
		ptr = -1;
		while (ptr != (*a)->content)
		{
			nbr = &((*a)->weight);
			if ((*nbr & 1) == 0)
				pb(b, a);
			else
			{
				if (ptr == -1)
					ptr = (*a)->content;
				ra(a);
			}
			*nbr = *nbr >> 1;
		}
		transfer_a_b(a, b);
		i++;
	}
}

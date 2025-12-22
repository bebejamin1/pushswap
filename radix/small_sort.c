/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeaurai <bbeaurai@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 08:53:36 by nbuchy            #+#    #+#             */
/*   Updated: 2025/12/22 10:58:19 by bbeaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	sort_verif(t_list *lst)
{
	t_list	*head1;

	head1 = lst->next;
	while (head1 != NULL)
	{
		if (lst->content > head1->content)
			return (0);
		head1 = head1->next;
		lst = lst->next;
	}
	return (1);
}

t_list	*find_biggest(t_list *stack)
{
	t_list	*biggest;

	biggest = NULL;
	while (stack != NULL)
	{
		if (biggest == NULL || stack->weight > biggest->weight)
			biggest = stack;
		stack = stack->next;
	}
	return (biggest);
}

t_list	*find_smallest(t_list *stack)
{
	t_list	*smallest;

	smallest = NULL;
	while (stack != NULL)
	{
		if (smallest == NULL || stack->weight < smallest->weight)
			smallest = stack;
		stack = stack->next;
	}
	return (smallest);
}

void	sort_three(t_list **a)
{
	t_list	*big_node;

	big_node = find_biggest(*a);
	while (big_node->content != ft_lstlast(*a)->content)
		ra(a);
	if ((*a)->weight > ((*a)->next)->weight)
		sa(a);
}

void	sort_five(t_list **a, t_list **b)
{
	if (sort_verif(*a) == 0)
	{
		while (ft_lstsize(*b) < 2)
		{
			if ((*a)->weight == 0 || (*a)->weight == 1)
				pb(b, a);
			else
				ra(a);
		}
		sort_three(a);
		pa(a, b);
		pa(a, b);
		if ((*a)->weight > ((*a)->next)->weight)
			sa(a);
	}
}

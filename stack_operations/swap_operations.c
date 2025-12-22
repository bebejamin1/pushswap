/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeaurai <bbeaurai@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 10:57:42 by bbeaurai          #+#    #+#             */
/*   Updated: 2025/12/22 10:57:43 by bbeaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_list **stack_a)
{
	t_list	*node1;
	t_list	*node2;

	if (stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	node1 = *stack_a;
	node2 = node1->next;
	node1->next = node2->next;
	node2->next = (*stack_a);
	*stack_a = node2;
	write(1, "sa\n", 3);
}

void	sb(t_list **stack_b)
{
	t_list	*node1;
	t_list	*node2;

	if (stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	node1 = *stack_b;
	node2 = node1->next;
	node1->next = node2->next;
	node2->next = (*stack_b);
	*stack_b = node2;
	write(1, "sb\n", 3);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	write(1, "ss\n", 3);
}

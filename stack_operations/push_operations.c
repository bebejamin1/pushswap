/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeaurai <bbeaurai@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 10:41:37 by bbeaurai          #+#    #+#             */
/*   Updated: 2025/12/22 10:41:40 by bbeaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (stack_b == NULL)
		return ;
	temp = (*stack_b)->next;
	(*stack_b)->next = NULL;
	ft_lstadd_front(stack_a, *stack_b);
	*stack_b = temp;
	write(1, "pa\n", 3);
}

void	pb(t_list **stack_b, t_list **stack_a)
{
	t_list	*temp;

	if (stack_a == NULL)
		return ;
	temp = (*stack_a)->next;
	(*stack_a)->next = NULL;
	ft_lstadd_front(stack_b, *stack_a);
	*stack_a = temp;
	write(1, "pb\n", 3);
}

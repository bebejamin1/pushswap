/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuchy <nbuchy@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:41:26 by nbuchy            #+#    #+#             */
/*   Updated: 2025/12/01 15:45:40 by nbuchy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_list **stack_a)
{
	t_list	*temp;

	if (stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	temp = *stack_a;
	while ((temp->next)->next != NULL)
	{
		temp = temp->next;
	}
	ft_lstadd_front(stack_a, temp->next);
	temp->next = NULL;
	write(1, "rra\n", 4);
}

void	rrb(t_list **stack_b)
{
	t_list	*temp;

	if (stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	temp = *stack_b;
	while ((temp->next)->next != NULL)
	{
		temp = temp->next;
	}
	ft_lstadd_front(stack_b, temp->next);
	temp->next = NULL;
	write(1, "rrb\n", 4);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rra(stack_a);
	rra(stack_b);
	write(1, "rrr\n", 4);
}
